/*
Neuvillette & Alhaitham
不要发呆，不要红温，对得起你的训练时间
题目名称 社团招新 道路修复 谐音替换 员工招聘
题目类型 传统型 传统型 传统型 传统型
目录 club road replace employ
可执行文件名 club road replace employ
输入文件名 club.in road.in replace.in employ.in
输出文件名 club.out road.out replace.out employ.out
每个测试点时限 1.0 秒 1.0 秒 1.0 秒 1.0 秒
内存限制 512 MiB 512 MiB 2048 MiB 512 Mi
*/
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
constexpr int N=1e5+7;
using namespace std;
int T,n;
ll a[N][5];
namespace brute
{
	int b[N];
	int cnt[10];
	ll ans=0;
	void dfs(int dep,ll sum)
	{
		if(dep>n)
		{
			ans=max(ans,sum);
			return;
		}
		for(int i=1;i<=3;i++)
		{
			if(cnt[i]+1<=(n>>1))
			{
				cnt[i]++;
				dfs(dep+1,sum+a[dep][i]);
				cnt[i]--;
			}
		}
	}
	inline ll solve()
	{
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++) b[i]=0;
		dfs(1,0);
		return ans;
	}
}
namespace greedy //贪心正解 
{
	ll delta[N];  //滑档代价 (第一志愿->第二志愿)
	inline ll max2(ll x,ll y,ll z)
	{
		if(x<y) swap(x,y);
		if(y<z) swap(y,z);
		if(x<z) swap(x,z);
		if(x<y) swap(x,y);
		if(y<z) swap(y,z);
		if(x<z) swap(x,z);
		if(x<y) swap(x,y);
		if(y<z) swap(y,z);
		if(x<z) swap(x,z);
		return y;
	}
	int cnt[10];
	inline int getID(ll x,ll y,ll z)
	{
		if(x>=y&&x>=z) return 1;
		else if(y>=z&&y>=z) return 2;
		else return 3;
	}
	inline ll solve()
	{
		ll ans=0;
		priority_queue<ll,vector<ll>,greater<ll>> q[4];  //滑档的队列 
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			ll mx1=max({a[i][1],a[i][2],a[i][3]}),mx1_id=getID(a[i][1],a[i][2],a[i][3]);  //第一志愿，第一志愿的编号
			cnt[mx1_id]++;
			ans=ans+mx1;
			delta[i]=mx1-max2(a[i][1],a[i][2],a[i][3]);
			q[mx1_id].push(delta[i]);
		}
		const int lim=n/2;   //开始滑档 
		for(int i=1;i<=3;i++)
		{
			while(cnt[i]>lim)
			{
				--cnt[i];
				ll tmp=q[i].top(); q[i].pop();
				ans-=tmp;
			}
		}
		return ans;
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);   //真的能关同步流吗？ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++) cin>>a[i][j];
		if(n<=1) cout<<brute::solve()<<endl;
		else cout<<greedy::solve()<<endl;
	}
	cout.flush();
	return 0;
}
/*
15:30 过大样例 
看一眼每个人最想去哪个部门，然后分配 
考虑每个人从第一志愿滑档到第二志愿的代价，如果第一志愿安排上发现有部门满人了就找几个代价最小的滑档 
*/
/*
会不会存在滑档次数超过两次的情况？ 题目保证n为偶数
所以很可能不存在 
100 99 80
90 80 70
80 70 30
70 50 30
*/ 
/*
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
我恨贪心，做到厌倦，做到呕吐。 
*/
