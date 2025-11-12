#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define Pair pair<long long,int>
#define ll long long
using namespace std;
struct A
{
	ll d[5];
	int num;
}a[100005];
int n;
ll ans;
void init()
{
	scanf("%d",&n);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i].d[1],&a[i].d[2],&a[i].d[3]);
		a[i].num=i;
	}
}
bool cmp1(A x,A y)
{
	return x.d[1]>y.d[1];
}
bool cmp2(A x,A y)
{
	return x.d[2]>y.d[2];
}
bool cmp3(A x,A y)
{
	return x.d[3]>y.d[3];
}
void Sort(int k)
{
	if(k==1)
	sort(a+1,a+1+n,cmp1);
	else if(k==2)
	sort(a+1,a+1+n,cmp2);
	else if(k==3)
	sort(a+1,a+1+n,cmp3);
}
bool vis[100005];
priority_queue<Pair> Que;
void work()
{
	//solution 1
	int size_1=0,size_2=0,size_3=0;
	ll ans_1=0,ans_2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].d[1]>max(a[i].d[2],a[i].d[3])&&size_1<n/2)
		{
			size_1++;
			ans_1+=a[i].d[1];
		}
		else if(a[i].d[2]>max(a[i].d[1],a[i].d[3])&&size_2<n/2)
		{
			size_2++;
			ans_1+=a[i].d[2];
		}
		else if(a[i].d[3]>max(a[i].d[1],a[i].d[2])&&size_3<n/2)
		{
			size_3++;
			ans_1+=a[i].d[3];
		}
	}
	ans=max(ans,ans_1);
	//solution 2
	for(int k=1;k<=3;k++)
	{
		ans_2=0;
		memset(vis,0,sizeof(vis));
		
		while(!Que.empty())
		Que.pop();
		
		Sort(k);
		int ano_1=(k+1)%3+1,ano_2=k%3+1;
//		cout<<"now "<<k<<endl;
//		cout<<ano_1<<' '<<ano_2<<endl; 
		for(int i=1;i<=n/2;i++)
		{
			vis[a[i].num]=1;
			Que.push(make_pair(max(a[i].d[ano_1],a[i].d[ano_2])-a[i].d[k],a[i].num));
			
			ans_2+=a[i].d[k];
		}
		
		for(int i=n/2+1;i<=n;i++)
		{
			while(vis[Que.top().second]==0)
			Que.pop();
			
			if(a[i].d[k]>max(a[i].d[ano_1],a[i].d[ano_2]))
			{
				if(Que.top().first+a[i].d[k]>max(a[i].d[ano_1],a[i].d[ano_2]))
				{
					ans_2+=Que.top().first+a[i].d[k];
					vis[Que.top().second]=0;
					Que.pop();
					vis[a[i].num]=1;
					Que.push(make_pair(max(a[i].d[ano_1],a[i].d[ano_2])-a[i].d[k],a[i].num));
				}
				else
				{
					ans_2+=max(a[i].d[ano_1],a[i].d[ano_2]);
				}
			}
			else
			{
				ans_2+=max(a[i].d[ano_1],a[i].d[ano_2]);
			}
		}
		ans=max(ans,ans_2);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		work();
		printf("%lld\n",ans);
	}
	return 0;
}
