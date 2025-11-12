#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int id;
	int now;
	int ttt;
	inline bool operator < (const node &x)const
	{
		return x.now>now;
	}
}tmp[10],maxn[15],maxm[15];
int T;
int n;
inline void read(int &x)
{
	int f=1;
	char c;
	c=getchar();
	if(c=='-')f=-1;
	else x=c-'0';
	c=getchar();
	while(c>='0'&&c<='9')
	{
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	x*=f;
}
int cnt1,cnt2,cnt3;
int ans;
priority_queue<node>q;
bool vis[200010];
signed main(void)
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--)
	{
		while(!q.empty())q.pop();
		read(n);
		for(int i=1;i<=n;++i)vis[i]=0;
		cnt1=cnt2=cnt3=ans=0;
		for(int i=1;i<=n;++i)
		{
			read(tmp[1].now),read(tmp[2].now),read(tmp[3].now);
			tmp[1].id=i,tmp[2].id=i,tmp[3].id=i;
//			sort(tmp+1,tmp+3+1);
//			ans+=tmp[1].now;
//			ans+=tmp[2].now;
//			ans+=tmp[3].now;
			if(n==2)
			{
				if(i%2==1)
				{
					for(int jx=1;jx<=3;++jx)
					{
//						cout << tmp[j].now << '\n';
						maxn[jx].now=tmp[jx].now;
//						cout << jx << ' ' << maxn[jx].now << '\n';
					}
				}
				else
				{
					for(int jx=1;jx<=3;++jx)
					{
//						cout << tmp[j].now << '\n';
						maxm[jx].now=tmp[jx].now;
//						cout << jx << ' ' << maxm[jx].now << '\n';
					}
				}
			}
			for(int j=1;j<=3;++j)q.push((node){tmp[j].id,tmp[j].now,j});
		}
		if(n==2)
		{
			for(int i=1;i<=3;++i)
			{
				for(int j=1;j<=3;++j)
				{
					if(i!=j)
					{
//						cout << maxn[1].now << '\n';
						ans=max(ans,maxn[i].now+maxm[j].now);
//						cout << i << ' ' << j << '\n';
//						cout << maxn[i].now << ' ' << maxm[j].now << '\n';
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		while(!q.empty())
		{
			node w=q.top();
			q.pop();
			if(vis[w.id])continue;
			if(w.ttt==1&&cnt1==n/2)continue;
			if(w.ttt==2&&cnt2==n/2)continue;
			if(w.ttt==3&&cnt3==n/2)continue;
			if(cnt1+cnt2+cnt3==n)break;
			vis[w.id]=1;
//			cout << w.id << '\n';
			if(w.ttt==1)++cnt1;
			if(w.ttt==2)++cnt2;
			if(w.ttt==3)++cnt3;
			ans+=w.now;
		}
//		cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << '\n';
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}