#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int mod=998244353;
int p[510],c[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	long long ans=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=18)
	{
		for(int i=1;i<=n;i++)p[i]=i;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt>=c[p[i]])cnt++;
				else if(s[i-1]=='0')cnt++;
			}
			if(n-cnt>=m)ans++;
		}while(next_permutation(p+1,p+1+n));
		cout<<ans%mod<<'\n';
	}
	else
	{
		cout<<0<<'\n';
	}
	return 0;
}
