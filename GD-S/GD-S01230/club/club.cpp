#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t;
int n,h;
int b[5];
bool c[N];
struct node{
	int k1,k2,k3;
}a[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int sum=0;
		b[1]=0;
		b[2]=0;
		b[3]=0;
		for(int i=1;i<=n;i++)
		{
			c[i]=false;			
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].k1,&a[i].k2,&a[i].k3);
		}
		if(n==2)
		{
			printf("%d",a[1].k2+a[2].k1);
			break;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].k1> a[i].k2 && a[i].k2>a[i].k3 && b[i]+1<n/2 && !c[i])
			{
				b[i]++;
				c[i]=true;
				sum+=a[i].k1;
			}else if(a[i].k2> a[i].k1 && a[i].k2>a[i].k3 && b[i]+1<n/2 && !c[i])
			{
				b[i]++;
				c[i]=true;
				sum+=a[i].k2;
			}else if(a[i].k3> a[i].k1 && a[i].k3>a[i].k2 && b[i]+1<n/2 && !c[i])
			{
				b[i]++;
				c[i]=true;
				sum+=a[i].k3;
			}else if(b[i]<n/2){
				b[i]++;
				c[i]=true;
				sum+=a[i].k2;
			}else{
				break;
			}		
		}
		printf("%d\n",sum);
	}
	return 0;
}
