#include <bits/stdc++.h>
using namespace std;

int T;

struct p
{
	int a,b,c;	
};
p happy[100005];
int a[100005],b[100005],c[100005];

bool cmp(int a,int b)
{
	return a>b;
}

void work(int n)
{
	int cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i = 1;i<=n;i++)
	{
		if(happy[i].a>=happy[i].b&&happy[i].a>=happy[i].c)
		{
			a[++cnt1]=min(happy[i].a-happy[i].b,happy[i].a-happy[i].c);
			sum+=happy[i].a;
		}
		else if(happy[i].b>happy[i].a&&happy[i].b>=happy[i].c)
		{
			b[++cnt2]=min(happy[i].b-happy[i].a,happy[i].b-happy[i].c);
			sum+=happy[i].b;
		}
		else if(happy[i].c>happy[i].b&&happy[i].c>happy[i].a)
		{
			c[++cnt3]=min(happy[i].c-happy[i].b,happy[i].c-happy[i].a);
			sum+=happy[i].c;
		}
	}
	if(cnt1>n/2)
	{
		sort(a+1,a+cnt1+1,cmp);
		for(;cnt1>n/2;cnt1--)
		{
			sum-=a[cnt1];
		}
	}
	if(cnt2>n/2)
	{
		sort(b+1,b+cnt2+1,cmp);
		for(;cnt2>n/2;cnt2--)
		{
			sum-=b[cnt2];
			
		}
	}
	if(cnt3>n/2)
	{
		sort(c+1,c+cnt3+1,cmp);
		for(;cnt3>n/2;cnt3--)
		{
			sum-=c[cnt3];
		}
	}
	cout<<sum<<endl;
	return ;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int _ = 1;_<=T;_++)
	{
		int n;
		cin>>n;
		for(int i = 1;i<=n;i++)
		{
			cin>>happy[i].a>>happy[i].b>>happy[i].c;
		}
		work(n);
	}
 } 
