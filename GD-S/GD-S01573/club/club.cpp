#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long x,y,z,maxn,id=0;
	bool operator < (const node &b) const
	{
		return abs(x-y)>abs(b.x-b.y);
	}
}a[100001];
bool cmp(node x,node y)
{
	return x.maxn>y.maxn;
}
long long t,n,f1,f2,ans,sum,cnt1,cnt2,cnt3;
void dfs(long long dep)
{
	if(dep>n)
	{
		if(cnt1>n/2||cnt2>n/2||cnt3>n/2)return;
		ans=max(ans,sum);
		return;
	}
	sum+=a[dep].x,cnt1++;
	dfs(dep+1);
	sum=sum-a[dep].x+a[dep].y,cnt2++,cnt1--;
	dfs(dep+1);
	sum=sum-a[dep].y+a[dep].z,cnt3++,cnt2--;
	dfs(dep+1);
	sum=sum-a[dep].z,cnt3--;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while(t--)
	{
		f1=f2=cnt1=cnt2=cnt3=0;
		ans=0;
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0)f1=1;
			if(a[i].z!=0||a[i].z!=0)f1=f2=1;
			a[i].maxn=max(a[i].x,a[i].y);
			if(a[i].maxn==a[i].x)a[i].id=1;
			else if(a[i].maxn==a[i].y)a[i].id=2;
			else a[i].id=3;
		}
		if(n<=30)
		{
			dfs(1);
			cout<<ans<<endl;
			continue;
		 } 
		if(!f1)
		{
			sort(a+1,a+n+1,cmp);
			for(long long i=1;i<=n/2;i++)
			{
				ans=ans+a[i].maxn;
			}
			cout<<ans<<endl;
			continue;
		}
		if(!f2)
		{
//			cout<<"OK"<<endl;
			sort(a+1,a+n+1);
			priority_queue<node> q1,q2;
			for(long long i=1;i<=n;i++)
			{
				if(a[i].id==1)q1.push(a[i]);
				else q2.push(a[i]);
				ans+=a[i].maxn;
			}
			if(q1.size()>q2.size())
			{
				while(q1.size()>q2.size())
				{
					node in=q1.top();
					long long d=q1.top().x,dt=q1.top().y;
					q1.pop();
					q2.push(in);
					ans=ans-d+dt;
//					cout<<ans<<endl;
				}
			}
			else if(q1.size()<q2.size())
			{
				while(q1.size()<q2.size())
				{
					node in=q2.top();
					long long d=q2.top().y,dt=q2.top().x;
					q2.pop();
					q1.push(in);
					ans=ans-d+dt;
//					cout<<ans<<endl;
				}
			}
			cout<<ans<<endl;
			continue;
		}
			sort(a+1,a+n+1,cmp);
			for(long long i=1;i<=n;i++)
			{
				ans=ans+a[i].maxn;
			}
			cout<<ans<<endl;
		
	}
	return 0;
}
//广东广州大学附属中学大学城校区CSP邮寄。我是luogu gzzym123456,在j组的考试（01770）中也写了邮寄 
//14:34 解压成功，试了一下DEV-C++，没有炸 
//15:12 T1还是不会做，看T2 
//没有心情写邮寄了，啊啊啊啊啊啊啊啊啊啊啊啊 
/*
1
4
5 5 0
4 1 0
3 3 0
1 2 0

*/
