#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
long long n,a[N][4],t,cnt[N],id[N],res;
vector <long long > v[5];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--) 
	{
		res=0;
		scanf("%lld",&n);
		for(int i=1;i<=3;i++) cnt[i]=0,v[i].clear();
		for(int i=1;i<=n;i++) 
		{
			long long mx=0,cmx=0;
			for(int j=1;j<=3;j++) 
			{
				scanf("%lld",&a[i][j]);
				mx=max(mx,a[i][j]); 
			}
			for(int j=1;j<=3;j++) if(a[i][j]==mx) 
			{
				id[i]=j;
				break;
			}
			for(int j=1;j<=3;j++) if(j!=id[i]) cmx=max(cmx,a[i][j]);
			v[id[i]].push_back(mx-cmx);
			cnt[id[i]]++;
			res+=mx;
		}
		for(int i=1;i<=3;i++) sort(v[i].begin(),v[i].end());
		for(int i=1;i<=3;i++) if(cnt[i]>n/2)
		{
			for(int j=1;j<=cnt[i]-n/2;j++) res-=v[i][j-1];
		} 
		printf("%lld\n",res);
	}
	return 0;
} 