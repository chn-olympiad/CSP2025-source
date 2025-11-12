#include <bits/stdc++.h>
using namespace std;
//16:19 才做完这道题快死了
//刚才只有最大的样例没过快吓死了，还好很快发现只是大于改成大于等于即可
//加油，我还有很多想要追求的东西，这只是第一步！ 
struct node
{
	long long a,b,c,d;
	bool operator < (const node&cmp) const
	{
		return d>cmp.d;
	}
};
node x[200010];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int __;
	scanf("%d",&__);
	while(__--)
	{
		long long n;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++) scanf("%lld%lld%lld",&x[i].a,&x[i].b,&x[i].c);
		for(long long i=1;i<=n;i++)
		{
			if(x[i].a>=x[i].b && x[i].a>=x[i].c) x[i].d=x[i].a-max(x[i].b,x[i].c);
			else if(x[i].b>=x[i].a && x[i].b>=x[i].c) x[i].d=x[i].b-max(x[i].a,x[i].c);
			else x[i].d=x[i].c-max(x[i].a,x[i].b);
		}
		sort(x+1,x+n+1);
		long long aa=0,bb=0,cc=0,sum=0,id=0;
		for(long long i=1;i<=n;i++)
		{
			if(aa==n/2 || bb==n/2 || cc==n/2)
			{
				id=i-1;
				break;
			}
			if(x[i].a>=x[i].b && x[i].a>=x[i].c) sum+=x[i].a,aa++;
			else if(x[i].b>=x[i].a && x[i].b>=x[i].c) sum+=x[i].b,bb++;
			else sum+=x[i].c,cc++;id++;
		}
		if(id==n)
		{
			cout<<sum<<endl;
			continue;
		}
		int f=0;
		if(aa==n/2) f=1;
		else if(bb==n/2) f=2;
		else if(cc==n/2) f=3;
		else
		{
			cout<<sum<<endl;
			continue;
		}
		for(long long i=id+1;i<=n;i++)
		{
			if(f==1) sum+=max(x[i].b,x[i].c);
			else if(f==2) sum+=max(x[i].a,x[i].c);
			else sum+=max(x[i].a,x[i].b);
		}
		cout<<sum<<endl;
	}
	return 0;
} 
