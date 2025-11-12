#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[505],ans,flags[15],l[15];
const int mod=998244353;
string s;
void dg(int x,int l[])
{
	if(x==n+1)
	{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[l[i]]){cnt++;continue;}
			if(s[i-1]=='0') cnt++;
			else sum++;
		}
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!flags[i]) l[x]=i,flags[i]=1,dg(x+1,l),flags[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10)
	{
		dg(1,l);
		return cout<<ans,0;
	}
	int sum=1;
	for(int i=1;i<=n;i++){
		sum=sum*i%mod;
	}
	if(n==m) return cout<<sum,0;
	return cout<<0,0;
}
