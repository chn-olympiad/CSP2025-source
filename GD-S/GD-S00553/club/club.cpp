#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,l,r) for(int i=(l);i>=(r);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
#define pi pair<int,int>
#define eb emplace_back
#define vi vector<int>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e5+7,inf=2e9;
int n,a[N][4],mx[N],cnt[4],s;
void work()
{
	s=0;
	fo(i,0,2) cnt[i]=0;
	scanf("%d",&n);
	fo(i,1,n)
	{
		fo(j,0,2) scanf("%d",&a[i][j]);
		mx[i]=0;
		fo(j,0,2) if(a[i][j]>a[i][mx[i]]) mx[i]=j;
		cnt[mx[i]]++;
		s+=a[i][mx[i]];
	}
	int o=-1;
	fo(i,0,2) if(cnt[i]>n/2) o=i;
	if(o!=-1)
	{
		vi v;
		fo(i,1,n) if(mx[i]==o)
		{
			int mn=inf;
			fo(j,0,2) if(o!=j) mn=min(mn,a[i][o]-a[i][j]);
			v.eb(mn);
		}
		sort(v.begin(),v.end());
		fu(i,0,cnt[o]-n/2) s-=v[i];
	}
	printf("%d\n",s);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) work();
}
