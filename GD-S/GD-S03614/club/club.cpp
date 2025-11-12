#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T,n,choose[N],ans,sum[4];
priority_queue<int,vector<int>,greater<int> > minncha[4];
struct node
{
	int a,b,c,d,e,f;
}k[N];
void add(int x)
{
	minncha[k[x-1].d].push(k[x-1].a-k[x-1].b);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>k[i-1].a>>k[i-1].b>>k[i-1].c;
		for(int i=1;i<=n;i++)
		{
			k[i-1].d=1,k[i-1].e=2,k[i-1].f=3;
			if(k[i-1].a<k[i-1].b) swap(k[i-1].a,k[i-1].b),swap(k[i-1].d,k[i-1].e);
			if(k[i-1].a<k[i-1].c) swap(k[i-1].a,k[i-1].c),swap(k[i-1].d,k[i-1].f);
			if(k[i-1].b<k[i-1].c) swap(k[i-1].b,k[i-1].c),swap(k[i-1].e,k[i-1].f);
		}
		for(int i=1;i<=3;i++)
			while(!minncha[i].empty()) minncha[i].pop();
		for(int i=1;i<=n;i++)
		{
			ans+=k[i-1].a;
			sum[k[i-1].d]++;
			add(i);
			if(sum[k[i-1].d]>n/2)
			{
				int tmp=minncha[k[i-1].d].top();
				ans-=tmp;
				sum[k[i-1].d]--;
				minncha[k[i-1].d].pop();
			}
		}
		cout<<ans<<endl;
		ans=0;
		memset(sum,0,sizeof sum);
	}
}
