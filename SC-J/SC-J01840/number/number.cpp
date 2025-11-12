#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	int n=s.size(),a[10]={};
	for(int i=0;i<10;i++)a[i]=0;
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]-->0)cout<<i;
	return 0;
}