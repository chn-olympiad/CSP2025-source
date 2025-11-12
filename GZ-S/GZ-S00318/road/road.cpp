//GZ-S00318 贵州省绥阳中学  王开润 
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
struct node{
	int a,b;
}q[200005];
node w[200005],e[200005];
bool com(node c,node b)
{
	return c.a>b.a;
}

int n;
node m[600020];
int t=1,f=1;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		bool biao[200005];
		memset(biao,0,sizeof(biao));
		int A=0,B=0,C=0;
		int AA=0,BB=01,CC=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>q[i].a>>w[i].a>>e[i].a;
			q[i].b=w[i].b=e[i].b=i;
			if(w[i].a==0)BB++;
			if(w[i].a==0)CC++;
		}
		if(BB==0&&CC==0)//性质A 
		{
			sort(q+1,q+1+n,com);
			for(int i=1;i<=n/2;i++)
				ans+=q[i].a;
		}//5
		for(int i=1;i<=n;i++)
		cout<<q[i].a<<" "<<q[i].b<<endl;
		cout<<ans<<endl;
		break; 
		
	}
	return 0;
 } 
