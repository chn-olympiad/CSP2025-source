#include<bits/stdc++.h>//luogu uid:956129
//#define int long long 
using namespace std;

namespace io
{
	inline int read(){int x=0,w=0;char c=0;while(!isdigit(c))w|=c=='-',c=getchar();while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();return w?-x:x;}
	template<typename T>void write(T x){if(x<0)x=-x,putchar('-');if(x>9)write(x/10);putchar(x%10+'0');}
	template<typename T>void write_(T x){write(x),putchar(' ');}
	template<typename T>void writeln(T x){write(x),putchar('\n');}
}
using namespace io;

/*
怎么是跷跷板空格awa
注意多测清空否，注意爆int否，注意#define int long long爆空间否
多测清空了 不会爆int 注释掉define了 
一个一眼的结论:每个人一定能分到一组.并且同时只会有一组的人数超过限制 
直接贪心显然错误，思考一下反悔贪心
这样,先放,放了再对多于n/2的进行反悔贪心
来看怎么反悔。即：让当前这一个进入这个，然后看哪里还有位置,挤出来一个负贡献最小的 
ohohoh,所以就不可能连续挤出来
ohohoh,这个题一定比去年T1要难,不过还好.
挤出来只能挤一个,所以挤就完了
过了所有大样例 复杂度 nlogn. 

差点被薄荷糖+水弄死。
*/

const int N=1e5+10;
int n,m,a[N][5];
struct node
{
	int u,v,w;//a[u][v] 
	friend bool operator<(const node&x,const node&y)
	{
//		if(x.w!=y.w)
		return x.w<y.w;
//		int sum1=0,sum2=0;
//		for(int i=1;i<=3;i++)
//		{
//			if(i==x.v) continue;
//			sum1=max(sum1,a[x.u][i]-x.w);
//		}
//		for(int i=1;i<=3;i++)
//		{
//			if(i==y.v) continue;
//			sum2=max(sum2,a[y.u][i]-y.w);
//		}
//		return sum1<sum2;//负值较大的排,不过没必要 
	}//大根堆 
};
priority_queue<node> q,p[5];

void solve()
{
	for(int j=1;j<=4;j++)
		while(!p[j].empty()) p[j].pop();
	n=read();m=n/2;int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++) a[i][j]=read();
		int x=max({a[i][1],a[i][2],a[i][3]});
		for(int j=1;j<=3;j++)
			if(x==a[i][j]) {q.push({i,j,a[i][j]});break;}
	}
	while(!q.empty())
	{
		auto [u,v,w]=q.top();q.pop();
		if(p[v].size()+1<=m)
		{
			ans+=w;//先尽量塞,这里传 u,挤到哪里的负权值.因为无论如何都能挤,挤到哪里其实不重要 
			int sum=-INT_MAX;
			for(int i=1;i<=3;i++)
			{
				if(i==v) continue;
				sum=max(sum,a[u][i]-w);
			}
			p[v].push({u,v,sum});
		}
		else p[4].push({u,v,w});//兄弟们我要反悔 
	}
//	cout<<ans<<"\n"; 
	while(!p[4].empty())
	{
		auto [u,v,w]=p[4].top();p[4].pop();
		auto [u1,v1,w1]=p[v].top();//显然能在 p[4] 里面的全部都是超出来的
		//有两个选择:挤出来或者换个位置
		int mx=a[u][1]+a[u][2]+a[u][3]-w-min({a[u][1],a[u][2],a[u][3]});//mx表示换个位置的最大值
//		cout<<v<<" "<<u<<" "<<u1<<" "<<w1<<" "<<w<<" "<<mx<<" "<<max(w1+w,mx)<<"\n";
		if(w1+w>mx)
		{
			ans+=w1+w,p[v].pop();//挤出来
			int sum=-INT_MAX;
			for(int i=1;i<=3;i++)
			{
				if(i==v) continue;
				sum=max(sum,a[u][i]-w);
			}
			p[v].push({u,v,sum});//塞进去 
		}
		else ans+=mx;//换位置 
	}
	writeln(ans);
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--) solve();
	return 0;
}
/*
*/
