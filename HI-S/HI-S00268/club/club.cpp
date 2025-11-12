#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
#define ll long long
ll n,bz,k,ans,a2[10],key,m;
struct sj
{
	int a,b,c;
	int d1,d2,d3;
}a1[maxn];
bool cmp(sj x,sj y)
{
	return x.c<y.c;
}
void bijiao(int x)
{
	if(a1[x].a<a1[x].b)
	{
		swap(a1[x].a,a1[x].b);
		swap(a1[x].d1,a1[x].d2);
	}
	if(a1[x].b<a1[x].c)
	{
		swap(a1[x].b,a1[x].c);
		swap(a1[x].d2,a1[x].d3);
	}
	if(a1[x].a<a1[x].b)
	{
		swap(a1[x].a,a1[x].b);
		swap(a1[x].d1,a1[x].d2);
	}
	a1[x].c=a1[x].a-a1[x].b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		a2[1]=a2[2]=a2[3]=0;
		m=0;
		ans=0;
		key=0;
		cin>>n;
		bz=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a1[i].a,&a1[i].b,&a1[i].c);
			a1[i].d1=1;a1[i].d2=2;a1[i].d3=3;
			k=i;
			bijiao(k);
			a2[a1[i].d1]++;
		}
		sort(a1+1,a1+n+1,cmp);
		if(a2[1]>bz)
		{
			m=1;
		}
		else if(a2[2]>bz)
		{
			m=2;
		}
		else if(a2[3]>bz)
		{
			m=3;
		}
		for(int i=n;i>=1;i--)
		{
			if(a1[i].d1==m&&key<bz)
			{
				ans+=a1[i].a;
				key++;
			}
			else if(a1[i].d1!=m)
			{
				ans+=a1[i].a;
			}
			else
			{
				ans+=a1[i].b;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
