#include<bits/stdc++.h>
using namespace std;
const int _ = 1e5+5;
int t,maxn=-1,n;
struct node{
	int d1,d2,d3,dmax=-1,dmax2=-1;
}a[_];
bool cmp(node x,node y)
{
	return x.dmax >y.dmax ;
}
void scan()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].d1 >>a[i].d2 >>a[i].d3 ;
		a[i].dmax =max(a[i].d1 ,a[i].d2 );
		a[i].dmax =max(a[i].dmax ,a[i].d3 );
		if(a[i].dmax ==a[i].d1 )
		{
			a[i].dmax2 =max(a[i].d2 ,a[i].d3 );
		}else if(a[i].dmax ==a[i].d2 ){
			a[i].dmax2 =max(a[i].d1 ,a[i].d3 );
		}else{
			a[i].dmax2 =max(a[i].d1 ,a[i].d2 );
		}
	}
	return;
}
int main()
{

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		scan();
		int sum=0;
		sort(a+1,a+1+n,cmp);
		if(n==2)
		{
			if(a[1].dmax ==a[1].d1 )
			{
				if(a[2].dmax ==a[2].d1 )
				{
					int a1=a[1].dmax +a[2].dmax2 ;
					int a2=a[1].dmax2 +a[2].dmax ;
					if(a1>a2)sum+=a1;
					else sum+=a2;
				}else{
					sum=sum+a[1].dmax +a[2].dmax ;
				}
			}else if(a[1].dmax ==a[1].d2 ){
				if(a[2].dmax ==a[2].d2 )
				{
					int a1=a[1].dmax +a[2].dmax2 ;
					int a2=a[1].dmax2 +a[2].dmax ;
					if(a1>a2)sum+=a1;
					else sum+=a2;
				}else{
					sum=sum+a[1].dmax +a[2].dmax ;
				}
			}else{
				if(a[2].dmax ==a[2].d3 )
				{
					int a1=a[1].dmax +a[2].dmax2 ;
					int a2=a[1].dmax2 +a[2].dmax ;
					if(a1>a2)sum+=a1;
					else sum+=a2;
				}else{
					sum=sum+a[1].dmax +a[2].dmax ;
				}
			}
		}else{
			for(int i=1;i<=n-1;i=i+2)
			{
				if(a[i].dmax ==a[i].d1 )
				{
					if(a[i+1].dmax ==a[i+1].d1 )
					{
						
						if(a[i+1].dmax +a[i+2].dmax2 >a[i+1].dmax2 +a[i+2].dmax )
						{
							sum=sum+a[i].dmax +a[i+1].dmax +a[i+2].dmax2 +a[i+3].dmax2 ;
							i=i+2;
							continue;
						}
						int a1=a[i].dmax +a[i+1].dmax2 ;
						int a2=a[i].dmax2 +a[i+1].dmax ;
						if(a1>a2)sum+=a1;
						else sum+=a2;
					}else{
						sum=sum+a[i].dmax +a[i+1].dmax ;
					}
				}else if(a[i].dmax ==a[i].d2 ){
					if(a[i+1].dmax ==a[i+1].d2 )
					{
						if(a[i+1].dmax +a[i+2].dmax2 >a[i+1].dmax2 +a[i+2].dmax )
						{
							sum=sum+a[i].dmax +a[i+1].dmax +a[i+2].dmax2 +a[i+3].dmax2 ;
							i=i+2;
							continue;
						}
						int a1=a[i].dmax +a[i+1].dmax2 ;
						int a2=a[i].dmax2 +a[i+1].dmax ;
						if(a1>a2)sum+=a1;
						else sum+=a2;
					}else{
						sum=sum+a[i].dmax +a[i+1].dmax ;
					}
				}else{
					if(a[i+1].dmax ==a[i+1].d3 )
					{
						if(a[i+1].dmax +a[i+2].dmax2 >a[i+1].dmax2 +a[i+2].dmax )
						{
							sum=sum+a[i].dmax +a[i+1].dmax +a[i+2].dmax2 +a[i+3].dmax2 ;
							i=i+2;
							continue;
						}
						int a1=a[i].dmax +a[i+1].dmax2 ;
						int a2=a[i].dmax2 +a[i+1].dmax ;
						if(a1>a2)sum+=a1;
						else sum+=a2;
					}else{
						sum=sum+a[i].dmax +a[i+1].dmax ;
					}
				}
			}
		}
		if(sum>maxn)maxn=sum;
		cout<<maxn<<'\n';
		maxn=-1;
	}
	return 0;
}
