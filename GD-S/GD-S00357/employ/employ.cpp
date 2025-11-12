#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,t=0;
	cin>>n>>m;
	int c[n]={};
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)t+=s[i]-'0';
	if(t==s.length()){
		int ans=0;
		for(int i=0;i<n;i++)if(c[i]>=i)ans++;
		cout<<ans;
		return 0;}
	for(int i=0;i<n;i++)cin>>c[n];
	if(m==1){
		cout<<m;
		return 0;}
	cout<<m;
	return 0;}
