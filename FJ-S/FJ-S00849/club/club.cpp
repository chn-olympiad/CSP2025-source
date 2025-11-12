#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Val
{
	int v,i;
};
bool Vcmp(Val x,Val y)
{
	return x.v>y.v;
}
Val a[100001][4];
int now[100001],cnt[4];
struct Best
{
	int i,v;	
	bool operator<(const Best& x)const
	{
		return v<x.v;
	}
};
int n;
priority_queue<Best>bst[4];
int pshv(int i)
{
	if(bst[a[i][now[i]].i].empty())
	{
		return a[i][now[i]+1].v;
	}
	Best bj=bst[a[i][now[i]].i].top();
	bst[a[i][now[i]].i].pop();
	int j=bj.i;
//	if(i==3)
//	{
//		cout<<"         "<<j<<'\n';
//	}
	if(cnt[a[j][now[j]+1].i]+1<=n/2)
	{
		bst[a[i][now[i]].i].push(bj);
//		if(i==3)
//		{
//			cout<<"             "<<a[i][now[i]].v<<' '<<a[j][now[j]].v<<' '<<a[j][now[j]+1].v<<'\n';
//		}
		return a[i][now[i]].v-a[j][now[j]].v+a[j][now[j]+1].v;
	}
	else
	{
		int res=a[i][now[i]].v-a[j][now[j]].v;
		now[j]++;
		res+=pshv(j);
		now[j]--;
		bst[a[i][now[i]].i].push(bj);
		return res;
	}
}
void psh(int i)
{
	if(bst[a[i][now[i]].i].empty())
	{
		return;
	}
	Best bj=bst[a[i][now[i]].i].top();
	bst[a[i][now[i]].i].pop();
	int j=bj.i;
	if(cnt[a[j][now[j]+1].i]+1<=n/2)
	{
		cnt[a[j][now[j]].i]--;
		now[j]++;
		cnt[a[j][now[j]].i]++;
	}
	else
	{
		cnt[a[j][now[j]].i]--;
		now[j]++;
		psh(j);
	}
//	cout<<"----"<<j<<' '<<pshv(i)<<'\n';
	bst[a[j][now[j]].i].push({j,-a[j][now[j]].v+pshv(j)});
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		for(int i=1;i<=3;i++)
		{
			while(bst[i].size())
			{
				bst[i].pop();
			}
		}
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1].v>>a[i][2].v>>a[i][3].v;
			a[i][1].i=1;
			a[i][2].i=2;
			a[i][3].i=3;
			sort(a[i]+1,a[i]+3+1,Vcmp);
			now[i]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
//			cout<<"--i = "<<i<<'\n';
			int maxans=0,nw=1;
			bool ned=0;
			for(;now[i]<=3;now[i]++)
			{
				if(cnt[a[i][now[i]].i]+1<=n/2)
				{
					if(a[i][now[i]].v>maxans)
					{
						maxans=a[i][now[i]].v;
						nw=now[i];
						ned=0;
					}
				}
				else
				{
					int res=pshv(i);
					if(res>0)
					{
						if(res>maxans)
						{
							maxans=res;
							nw=now[i];
							ned=1;
						}
					}
				}
			}
			ans+=maxans;
			now[i]=nw;
			cnt[a[i][now[i]].i]++;
			if(cnt[a[i][now[i]+1].i]+1<=n/2)
			{
				bst[a[i][now[i]].i].push({i,-a[i][now[i]].v+a[i][now[i]+1].v});
			}
			else
			{	
				bst[a[i][now[i]].i].push({i,-a[i][now[i]].v+pshv(i)});
			}
			if(ned)
			{
				psh(i);
			}
//			for(int j=1;j<=3;j++)
//			{
//				if(bst[j].empty())
//				{
//					continue;
//				}
//				cout<<"   "<<j<<" : "<< bst[j].top().i<<' '<<bst[j].top().v<<' '<<now[bst[j].top().i] <<'\n';
//			}
//			for(int j=1;j<=n;j++)
//			{
//				cout<<a[j][now[j]].i<<' ';
//			}
//			cout<<'\n';
//			cout<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<'\n';
//			cout<<ans<<'\n';
//			cout<<'\n';
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<now[i]<<' ';
//		}
		cout<<ans<<'\n';
	}
}
