#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
using namespace std;
int T,n,m,k,ans;
int t[3];
int a[500005];
int s[500005];
int vis[500005];
bool flag;
vector<pair<int,int>> can,xuan;
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.second<b.second;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	rep(i,1,n) cin>>a[i],s[i]=(s[i-1]^a[i]),flag=max(flag,a[i]!=1);
	if(!flag) return cout<<n/2,0;
	else if(k<=1)
	{
		rep(i,1,n) 
		{
			t[a[i]]++;
			if(a[i]==1&&a[i+1]==1) a[i]=a[i+1]=0,t[1]++,t[0]++,++i;
		}
		return cout<<t[k],0;
	}
	else
	{
		rep(i,1,n)
		{
			rep(j,i,n)
			{
				if((s[j]^s[i-1])==k)
				{
					can.push_back({i,j});
					break;
				}
			}
		}
		sort(can.begin(),can.end(),cmp);
		rek(i,0,can.size())
		{
			int x=can[i].first,y=can[i].second;
			bool flag=1;
			rek(i,0,xuan.size())
			{
				int xx=xuan[i].first,yy=xuan[i].second;
				if((yy>=x&&yy<=y)||(xx<=y&&xx>=x))
				{
					flag=0;
					break;
				}
			}
			if(flag) ans++,xuan.push_back(can[i]);
		}
		cout<<ans;
	}
}
