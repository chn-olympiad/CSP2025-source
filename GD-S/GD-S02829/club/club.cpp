#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
pair<int,int>a[100010][4],f[100010];
int v[4];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t1,n,t;
	cin>>t1;
	while(t1--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1].first>>a[i][2].first>>a[i][3].first;	
			a[i][1].second=1;a[i][2].second=2;a[i][3].second=3;
			if(a[i][1]>a[i][2])swap(a[i][1],a[i][2]);
			if(a[i][2]>a[i][3])swap(a[i][2],a[i][3]);
			if(a[i][1]>a[i][2])swap(a[i][1],a[i][2]);
			f[i]={a[i][3].first-a[i][2].first,i};		
		}
		sort(f+1,f+n+1,greater<pair<int,int>>());
		t=0;
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++)
			if(v[a[f[i].second][3].second]*2<n)
			{
				v[a[f[i].second][3].second]++;
				t+=a[f[i].second][3].first;
			}
			else
			{
				v[a[f[i].second][2].second]++;
				t+=a[f[i].second][2].first;				
			}
		cout<<t<<'\n';
	}
	return 0;
} 
