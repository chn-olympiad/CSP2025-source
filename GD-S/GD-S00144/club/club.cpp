#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int T;
int n;
int a[N][4];
struct node
{
	int val,id;
	bool operator>(const node &p) const
	{
		return val>p.val;
	}
};
priority_queue<node,vector<node>,greater<node> > qmn[4];
int pos[N][4];
int cnt[4];
void sot(int c,int &x,int &y,int &z)
{
	if(a[c][x]<=a[c][y]) swap(x,y);
	if(a[c][y]<=a[c][z]) swap(y,z);
	if(a[c][x]<=a[c][y]) swap(x,y);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		for(int i=1;i<=3;i++) while(!qmn[i].empty()) qmn[i].pop();
		int ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			pos[i][1]=1;pos[i][2]=2;pos[i][3]=3;
			sot(i,pos[i][1],pos[i][2],pos[i][3]);
		}
		for(int i=1;i<=n;i++)
		{
			if(cnt[pos[i][1]]+1<=n/2)
			{
				cnt[pos[i][1]]++;
				ans+=a[i][pos[i][1]];
				qmn[pos[i][1]].push
				({a[i][pos[i][1]]-a[i][pos[i][2]],i});
			}
			else
			{
				int ch_id=qmn[pos[i][1]].top().id;
				int cost=qmn[pos[i][1]].top().val;
				if(cost<a[i][pos[i][1]])
				{
					qmn[pos[i][1]].pop();
					cnt[pos[ch_id][2]]++;
					qmn[pos[i][1]].push
					({a[i][pos[i][1]]-a[i][pos[i][2]],i});
					ans=ans-cost+a[i][pos[i][1]];
				}
				else
				{
					ans+=a[i][pos[i][2]];
					cnt[pos[i][2]]++;
				}
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}
