#include<bits/stdc++.h>
using ll=long long;
using namespace std;
/*
对了可以不要让我上年度奇葩代码大赏好吗，我只是喜欢在代码里面碎碎念而已（离开……） 
先贪心，让每个人进他们最爱的部门，然后再反悔，让最爱和次爱的差最小的人出去 
好了，不管了样例过了就是过了 
*/

struct Day{
	int k, cha;
	bool operator <(const Day &x)const
	{
		return x.cha < cha;//让差小的排前面 
	}
};

int a[100005][5], num[5];
bool f[100005][5]; 
priority_queue<Day> q[4];

void qici(Day p)
{
	if((int)(f[p.k][1]+f[p.k][2]+f[p.k][3])==2)
	{
		if(!f[p.k][1]){num[1]++;q[1].push((Day){p.k,1000000009});}
		else if(!f[p.k][2]){num[2]++;q[2].push((Day){p.k,1000000009});}
		else {num[3]++;q[3].push((Day){p.k,1000000009});}
	}
	else if(f[p.k][1])
	{
		if(a[p.k][2] >= a[p.k][3])
		{num[2]++;q[2].push((Day){p.k,a[p.k][2]-a[p.k][3]});} 
		else 
		{num[3]++;q[3].push((Day){p.k,a[p.k][3]-a[p.k][2]});}
	}
	else if(f[p.k][2])
	{
		if(a[p.k][1] >= a[p.k][3])
		{num[1]++;q[1].push((Day){p.k,a[p.k][1]-a[p.k][3]});} 
		else 
		{num[3]++;q[3].push((Day){p.k,a[p.k][3]-a[p.k][1]});}
	}
	else 
	{
		if(a[p.k][1] >= a[p.k][2])
		{num[1]++;q[1].push((Day){p.k,a[p.k][1]-a[p.k][2]});} 
		else 
		{num[2]++;q[2].push((Day){p.k,a[p.k][2]-a[p.k][1]});}
	}
	
	return ;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//q[0].push((Day){1,1});q[0].push((Day){0,0});printf("%d\n",q[0].top().cha);
	//这个没错 
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof f);
		num[1]=num[2]=num[3]=0;
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop(); 
		//多测不清空，亲人两行泪 
		int n;
		scanf("%d",&n);
		ll ans = 0;
		for(int i = 1;i <= n;i++)
		{
			int p;
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{p=1;f[i][1]=1;num[1]++;q[1].push((Day){i,a[i][1]-max(a[i][2],a[i][3])});}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{p=2;f[i][2]=1;num[2]++;q[2].push((Day){i,a[i][2]-max(a[i][1],a[i][3])});}
			else 
			{p=3;f[i][3]=1;num[3]++;q[3].push((Day){i,a[i][3]-max(a[i][1],a[i][2])});}
			ans += a[i][p]; 
			if(num[p] > (n>>1))
			{
				num[p]--;
				Day P = q[p].top();q[p].pop();
				ans -= P.cha;
				qici(P);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
