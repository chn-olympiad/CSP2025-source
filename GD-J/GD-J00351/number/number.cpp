#include<bits/stdc++.h>
using namespace std;
int f[1000005],t=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i]))f[++t]=s[i]-'0';
	}
	sort(f+1,f+1+t);
	for(int i=t;i>=1;i--)cout<<f[i];
}
