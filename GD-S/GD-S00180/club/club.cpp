#include<bits/stdc++.h>
using namespace std;
long long int ji[1010101];
long long int cho[1001100];
long long int vis[1010101];
long long int a[1010101],b[101011],c[1101011];
long long int tot=0;
long long int maxx=-1;
void choose(long long int n,long long int x)
{
	if(x==n+1)
	{
		long long int sum=0;
		for(long long int i=1;i<=n;i++)
		{
			if(cho[i]==1)
			{
				sum+=a[i];
			}
			if(cho[i]==2)
			{
				sum+=b[i];
			}
			if(cho[i]==3)
			{
				sum+=c[i];
			}
		}
		if(sum>maxx)
		{
			maxx=sum;
		}
	}
	else
	{
		for(long long int i=1;i<=tot;i++)
		{
			if(vis[i]==0)
			{
				vis[i]=1;
				cho[x]=ji[i];
				choose(n,x+1);
				vis[i]=0;
			}
		} 
	}
}
void A(long long int n)
{
	sort(a+1,a+n+1);
	cout<<a[1]+a[2]<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	long long int T;
	cin>>T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		memset(cho,0,sizeof(cho));
		memset(ji,0,sizeof(ji));
		long long int n;
		cin>>n;
		for(long long int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		for(long long int i=1;i<=n;i++)
		{
			if(b[i]==0 and c[i]==0)
			{
				A(n);
				goto Go;
			}
		}
		for(long long int i=1;i<=3;i++)
		{
			for(long long int j=1;j<=n/2;j++)
			{
				ji[++tot]=i;
			}
		}
		choose(n,0);
		cout<<maxx<<endl;
		maxx=-1;
		Go:;
	}
}
