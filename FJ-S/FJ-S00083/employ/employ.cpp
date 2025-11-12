#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],p[N];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	s='%'+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)p[i]=i;
	int ans=0;
	do
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(sum>=c[p[i]]){sum++;continue;}
			sum+=!(s[i]-'0');
		}
		if(n-sum>=m)ans++;
		if(ans>=mod)ans-=mod;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}

