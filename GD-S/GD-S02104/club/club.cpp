#include<bits/stdc++.h>
#define int long long
using namespace std;
struct idv
{
	int x,y,z;
};
idv mem[100005];
vector<int>x,y,z;
int t,n,lim,sumx,sumy,sumz,les[100005],head,ans;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
void solve(int id)
{
	if(mem[id].x>=mem[id].y&&mem[id].x>=mem[id].z)
	{
		x.push_back(id);
		ans+=mem[id].x;
		sumx++;	
	}
	else if(mem[id].y>=mem[id].x&&mem[id].y>=mem[id].z)
	{
		y.push_back(id);
		ans+=mem[id].y;
		sumy++;
	}
	else
	{
		z.push_back(id);
		ans+=mem[id].z;
		sumz++;
	}
	return;
}
bool cmp(int a,int b)
{
	return a>b;
} 
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		lim=n/2;
		ans=0;
		head=0;
		sumx=0;sumy=0;sumz=0;
		x.clear();y.clear();z.clear();
		for(int i=1;i<=n;i++)
		{
			mem[i].x=read();mem[i].y=read();mem[i].z=read();
			solve(i);
		}
		if(sumx>lim) for(int i:x) les[++head]=min(mem[i].x-mem[i].y,mem[i].x-mem[i].z);
		else if(sumy>lim) for(int i:y) les[++head]=min(mem[i].y-mem[i].x,mem[i].y-mem[i].z);
		else if(sumz>lim) for(int i:z) les[++head]=min(mem[i].z-mem[i].x,mem[i].z-mem[i].y);
		if(head>lim) sort(les+1,les+head+1,cmp);
		while(head>lim)
		{
			ans-=les[head];
			head--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
