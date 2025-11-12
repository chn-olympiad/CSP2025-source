#include<bits/stdc++.h>
using namespace std;
string s;
int s_len,a[1000001],a_len;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s_len=s.size();
	for(int i=0;i<s_len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[a_len++]=(s[i]-'0');
		}
	}
	sort(a,a+a_len,cmp);
	for(int i=0;i<a_len;i++){
		cout<<a[i];
	}
	return 0;
}
