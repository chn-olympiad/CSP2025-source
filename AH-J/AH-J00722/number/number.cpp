#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	 freopen("number.in","r",stdin);
	 freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	long long d=0;
	long long a[len];
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			d++;
			a[d]=s[i]-'0';
		}
	}
	sort(a+1,a+d+1,cmp);
	for(int i=1;i<=d;i++){
		cout<<a[i];
	}
	return 0;
}
