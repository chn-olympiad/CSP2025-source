#include<iostream>//club ok
#include<algorithm>
#include<queue>
#include<cstring>
#define PII pair<int,int> 
using namespace std;
const int N=1e6+10;
struct yee
{
	int a,b,c,i1,i2,i3;
}f[N];
int n,m,t,p[4];
long long sum;
priority_queue<int,vector<int>,greater<int>> q[4];//小根堆
void exc(int s)
{
	while(p[s]>n/2)
	{
		sum-=q[s].top();
		q[s].pop();
		p[s]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int a,b,c,a1=1,b1=2,c1=3;
			scanf("%d %d %d",&a,&b,&c);
			if(b<c)
				swap(b,c),swap(b1,c1);
			if(a<b)
				swap(a,b),swap(a1,b1);
			if(b<c)
				swap(b,c),swap(b1,c1);
			//a>b>c
			f[i].a=a;
			f[i].b=a-b;
			f[i].c=b-c;
			f[i].i1=b1,f[i].i2=c1,f[i].i3=a1;
			sum+=a;
			q[a1].push(f[i].b);//找差值最小 
			p[a1]++;
		}
		if(p[1]>n/2)
			exc(1);
		if(p[2]>n/2)
			exc(2);
		if(p[3]>n/2)
			exc(3);
		printf("%lld\n",sum);
		while(q[3].size())
			q[3].pop();
		while(q[1].size())
			q[1].pop();
		while(q[2].size())
			q[2].pop();
		for(int i=1;i<=3;i++)
			p[i]=0;
	}
	
	return 0;
}
