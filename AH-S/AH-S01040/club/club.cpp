#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long ans=0;
struct cluber
{
	int a1[5],maxn,minn=114514,mixn=114514;
	int maxm,minm=114514,mixm,jian;
	bool vis=0;
}a[N];
bool cmp(cluber x,cluber y)
{
	return x.maxm>y.maxm;
}
int clubnum[5];
priority_queue<int> q1;
priority_queue<int> q2;
priority_queue<int> q3;
void join1(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(clubnum[a[i].maxn]<n/2)
		{
			clubnum[a[i].maxn]++;
			ans+=a[i].maxm;
			//cout<<a[i].maxm<<' ';
			int ch=a[i].maxm-a[i].mixm;
			if(a[i].maxn==1)
				q1.push(-ch);
			else if(a[i].maxn==2)
				q2.push(-ch);
			else if(a[i].maxn==3)
				q3.push(-ch);
		}
		else if(clubnum[a[i].maxn]>=n/2)
		{
			//int ch=a[i].maxm-a[i].mixm;
			//cout<<ch<<' ';
			int minch=0;
			int ch=a[i].maxm-a[i].mixm;
			if(a[i].maxn==1)
				minch=-q1.top();
			else if(a[i].maxn==2)
				minch=-q2.top();
			else if(a[i].maxn==3)
				minch=-q3.top();
			//cout<<minch<<' ';
			if(minch<ch)
			{
				ans+=a[i].maxm;
				ans-=minch;
				if(a[i].maxn==1)
				{
					q1.pop();
					q1.push(-ch);
				}
				
				else if(a[i].maxn==2)
				{
					q2.pop();
					q2.push(-ch);
				}
				
				else if(a[i].maxn==3)
				{
					q3.pop();
					q3.push(-ch);
				}
				
				//q.pop();
				//q.push(-ch);
			}
			else
			{
				ans+=a[i].mixm;
			}
		}
		
	}
	cout<<ans<<endl;
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
				cin>>a[j].a1[k];
			for(int k=1;k<=3;k++)
				a[j].maxn=max(a[j].maxn,a[j].a1[k]);
			for(int k=1;k<=3;k++)
				if(a[j].maxn==a[j].a1[k])
				{
					a[j].maxn=k;
					break;
				}
			for(int k=1;k<=3;k++)
				a[j].minn=min(a[j].minn,a[j].a1[k]);
			for(int k=1;k<=3;k++)
				if(a[j].minn==a[j].a1[k])
				{
					a[j].minn=k;
					break;
				}		
			for(int k=1;k<=3;k++)
				if(k!=a[j].minn && k!=a[j].maxn)
				{
					a[j].mixn=k;
					break;
				}
			a[j].maxm=a[j].a1[a[j].maxn];
			a[j].minm=a[j].a1[a[j].minn];
			a[j].mixm=a[j].a1[a[j].mixn];
			a[j].jian=a[j].maxm-a[j].mixm;
		}
		//for(int j=1;j<=n;j++)
		//	cout<<a[j].maxn<<' '<<a[j].mixn<<' '<<a[j].minn<<' '<<a[j].maxm<<' '<<a[j].mixm<<' '<<a[j].minm<<endl;
		sort(a+1,a+n+1,cmp);
		//for(int j=1;j<=n;j++)
		//	cout<<a[j].maxn<<' '<<a[j].mixn<<' '<<a[j].minn<<' '<<a[j].maxm<<' '<<a[j].mixm<<' '<<a[j].minm<<"   "<<a[j].jian<<endl;
		join1(n);
		ans=0;
		//q.clear();
		while(!q1.empty())
			q1.pop();
		while(!q2.empty())
			q2.pop();
		while(!q3.empty())
			q3.pop();
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
				a[j].a1[k]=0;
			a[j].maxm=0;
			a[j].mixm=0;
			a[j].minm=114514;
			a[j].maxn=0;
			a[j].mixn=0;
			a[j].minn=114514;
			a[j].jian=0;
		}
		for(int i=1;i<=3;i++)
			clubnum[i]=0;
	}
	return 0;
}
