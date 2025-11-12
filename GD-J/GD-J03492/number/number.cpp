#include<bits/stdc++.h>
using namespace std;
long long l,t,a[2222222];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++t]=int(s[i]-'0');
		}
	}
	sort(a+1,a+1+t);
	for(int i=t;i>=1;i--) cout<<a[i];
	return 0;
}
