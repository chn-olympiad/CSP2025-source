#include<bits/stdc++.h>
using namespace std;
long long n,t,m,k,p[10001],i,j,ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(i=0;i<=s.size();i++)if(s[i]=='0')t++;
	if(t>m){
		cout<<0;return 0;
	}
	for(i=1;i<=n;i++){
		cin>>p[i];ans*=(1<<p[i]);ans%=998244353;
	}
	ans/=(1<<(m-1));ans/=(1<<(s.size()-t));
	cout<<ans;
	return 0; 
} 
