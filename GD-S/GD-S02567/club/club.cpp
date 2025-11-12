#include<bitset>
#include<iostream>
#include<cstring>
#include<queue>
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;
int t,n,a[100005][4],ans,cnt[4];
bitset<100005> used;
auto cmpA=[](int x,int y)
{
	return a[x][0]<a[y][0];
};
auto cmpB=[](int x,int y)
{
	return a[x][1]<a[y][1];
};
auto cmpC=[](int x,int y)
{
	return a[x][2]<a[y][2];
};
priority_queue<int,vector<int>,decltype(cmpA)> qA(cmpA);
priority_queue<int,vector<int>,decltype(cmpB)> qB(cmpB);
priority_queue<int,vector<int>,decltype(cmpC)> qC(cmpC);
auto cmp_WA=[](int x,int y)
{
	return a[x][0]-MAX(a[x][1],a[x][2])>a[y][0]-MAX(a[y][1],a[y][2]);
};
auto cmp_WB=[](int x,int y)
{
	return a[x][1]-MAX(a[x][0],a[x][2])>a[y][1]-MAX(a[y][0],a[y][2]);
};
auto cmp_WC=[](int x,int y)
{
	return a[x][2]-MAX(a[x][1],a[x][0])>a[y][2]-MAX(a[y][1],a[y][0]);
};
priority_queue<int,vector<int>,decltype(cmp_WA)> WA(cmp_WA);
priority_queue<int,vector<int>,decltype(cmp_WB)> WB(cmp_WB);
priority_queue<int,vector<int>,decltype(cmp_WC)> WC(cmp_WC);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		a[n+1][0]=a[n+1][1]=a[n+1][2]=-1e9;
		cnt[0]=cnt[1]=cnt[2]=0;
		ans=0;
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<3; ++j)
			{
				cin>>a[i][j];
			}
			qA.push(i);
			qB.push(i);
			qC.push(i);
		}
		while(qA.top()!=n+1&&qB.top()!=n+1&&qC.top()!=n+1)
		{
			if(a[qA.top()][0]>=MAX(a[qB.top()][1],a[qC.top()][2]))
			{
				if(used[qA.top()])
				{
					qA.pop();
					if(qA.empty()) qA.push(n+1);
					continue;
				}
				if(cnt[0]<(n>>1))
				{
					ans+=a[qA.top()][0];
					cnt[0]++;
					used[qA.top()]=true;
					WA.push(qA.top());
					qA.pop();
					if(qA.empty()) qA.push(n+1);
				}
				else
				{
					if(!WA.empty()&&a[WA.top()][0]-MAX(a[WA.top()][1],a[WA.top()][2])<a[qA.top()][0]-MAX(a[qA.top()][1],a[qA.top()][2]))
					{
						used[WA.top()]=false;
						ans-=a[WA.top()][0];
						qB.push(WA.top());
						qC.push(WA.top());
						WA.pop();
						ans+=a[qA.top()][0];
						used[qA.top()]=true;
						WA.push(qA.top());
						qA.pop();
						if(qA.empty()) qA.push(n+1);
					}
					else
					{
						qA.pop();
						if(qA.empty()) qA.push(n+1);
						continue;
					}
				}
			}
			else if(a[qB.top()][1]>=MAX(a[qC.top()][2],a[qA.top()][0]))
			{
				if(used[qB.top()])
				{
					qB.pop();
					if(qB.empty()) qB.push(n+1);
					continue;
				}
				if(cnt[1]<(n>>1))
				{
					ans+=a[qB.top()][1];
					cnt[1]++;
					used[qB.top()]=true;
					WB.push(qB.top());
					qB.pop();
					if(qB.empty()) qB.push(n+1);
				}
				else
				{
					if(!WB.empty()&&a[WB.top()][1]-MAX(a[WB.top()][0],a[WB.top()][2])<a[qB.top()][1]-MAX(a[qB.top()][0],a[qB.top()][2]))
					{
						used[WB.top()]=false;
						ans-=a[WB.top()][1];
						qA.push(WB.top());
						qC.push(WB.top());
						WB.pop();
						ans+=a[qB.top()][1];
						used[qB.top()]=true;
						WB.push(qB.top());
						qB.pop();
						if(qB.empty()) qB.push(n+1);
					}
					else
					{
						qB.pop();
						if(qB.empty()) qB.push(n+1);
						continue;
					}
				}
			}
			else
			{
				if(used[qC.top()])
				{
					qC.pop();
					if(qC.empty()) qC.push(n+1);
					continue;
				}
				if(cnt[2]<(n>>1))
				{
					ans+=a[qC.top()][2];
					cnt[2]++;
					used[qC.top()]=true;
					WC.push(qC.top());
					qC.pop();
					if(qC.empty()) qC.push(n+1);
				}
				else
				{
					if(!WC.empty()&&a[WC.top()][2]-MAX(a[WC.top()][1],a[WC.top()][0])<a[qC.top()][2]-MAX(a[qC.top()][1],a[qC.top()][0]))
					{
						used[WC.top()]=false;
						ans-=a[WC.top()][2];
						qA.push(WC.top());
						qB.push(WC.top());
						WC.pop();
						ans+=a[qC.top()][2];
						used[qC.top()]=true;
						WC.push(qC.top());
						qC.pop();
						if(qC.empty()) qC.push(n+1);
					}
					else
					{
						qC.pop();
						if(qC.empty()) qC.push(n+1);
						continue;
					}
				}
			}
		}
		cout<<ans<<'\n';
		qA.pop();
		qB.pop();
		qC.pop();
		while(!WA.empty()) WA.pop();
		while(!WB.empty()) WB.pop();
		while(!WC.empty()) WC.pop();
		used=0;
	}
}
