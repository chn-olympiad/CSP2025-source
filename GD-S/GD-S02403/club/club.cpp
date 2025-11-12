#include<bits/stdc++.h>
using namespace std;
const int N=1e6,N5=3e3;
long long t,n,ans,bz[4];
struct O{
	long long a,b,c;
}l[N];
struct node{
	long long w,z;
	
	node(long long x,long long y): w(x),z(y) {}
	
	bool operator < (const node &b) const {
		return z>b.z;
	}
};priority_queue<node> qa,qb,qc;
int check(int x,int wf)
{
	bool ture1=false,ture2=false;
	if(x==1)
	{
		node t=qa.top();
		long long w=t.w,z=t.z,
		zf1=l[w].b+l[wf].a,zf2=l[w].c+l[wf].a;
		if(zf1>z)ture1=true;
		if(zf2>z)ture2=true;
		if(ture1&&ture2)
		{
			if(zf1>zf2)return 2;
			else return 3;
		}
		else if(ture1)return 2;
		else if(ture2)return 3;
		return 0;
	}
	if(x==2)
	{
		node t=qb.top();
		long long w=t.w,z=t.z,
		zf1=l[w].b+l[wf].a,zf2=l[w].b+l[wf].c;
		if(zf1>z)ture1=true;
		if(zf2>z)ture2=true;
		if(ture1&&ture2)
		{
			if(zf1>zf2)return 1;
			else return 3;
		}
		else if(ture1)return 1;
		else if(ture2)return 3;
		return 0;
	}
	if(x==3)
	{
		node t=qc.top();
		long long w=t.w,z=t.z,
		zf1=l[w].c+l[wf].a,zf2=l[w].c+l[wf].b;
		if(zf1>z)ture1=true;
		if(zf2>z)ture2=true;
		if(ture1&&ture2)
		{
			if(zf1>zf2)return 1;
			else return 2;
		}
		else if(ture1)return 1;
		else if(ture2)return 2;
		return 0;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(bz,0,sizeof(bz));
		for(int i=1;i<=n;i++)
			cin>>l[i].a>>l[i].b>>l[i].c;
		for(int i=1;i<=n;i++)
		{
			bool ture=false;
			int pd=0;
			if(l[i].a>l[i].b&&l[i].a>l[i].c)
			{
				pd=check(1,i);
				if(bz[1]<n/2)
					qa.push(node(l[i].a,i)),bz[1]++;
				else if(pd)
				{
					qa.pop();qa.push(node(l[i].a,i));
					if(pd==2)qb.push(node(l[i].b,i)),bz[2]++;
					else qc.push(node(l[i].c,i)),bz[3]++;
				}
				else if(l[i].b>l[i].c)qb.push(node(l[i].b,i)),bz[2]++;
				else qc.push(node(l[i].c,i)),bz[3]++;
			}
			if(l[i].b>l[i].a&&l[i].b>l[i].c)
			{
				pd=check(2,i);
				if(bz[2]<n/2)
					qb.push(node(l[i].b,i)),bz[2]++;
				else if(pd)
				{
					qb.pop();qb.push(node(l[i].b,i));
					if(pd==1)qa.push(node(l[i].a,i)),bz[1]++;
					else qc.push(node(l[i].c,i)),bz[3]++;
				}
				else if(l[i].a>l[i].c)qa.push(node(l[i].a,i)),bz[1]++;
				else qc.push(node(l[i].c,i)),bz[3]++;
			}
			if(l[i].c>l[i].a&&l[i].c>l[i].b)
			{
				pd=check(3,i);
				if(bz[3]<n/2)
					qc.push(node(l[i].c,i)),bz[3]++;
				else if(pd)
				{
					qc.pop();qc.push(node(l[i].c,i));
					if(pd==2)qb.push(node(l[i].b,i)),bz[2]++;
					else qa.push(node(l[i].a,i)),bz[1]++;
				}
				else if(l[i].b>l[i].a)qb.push(node(l[i].b,i)),bz[2]++;
				else qa.push(node(l[i].a,i)),bz[1]++;
			}
		}
		ans=0;
		cout<<"?? "<<ans<<'\n';
	}
	return 0;
}
