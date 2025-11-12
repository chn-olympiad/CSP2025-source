#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
string sum="1";
bool hhh(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int q=0,z=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[q]=(int)s[i]-'0';
			q++;
		}
	}
	sort(a,a+q,hhh);
	for(int i=0;i<q;i++){
		cout<<a[i];
	}
}
