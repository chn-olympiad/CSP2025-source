#include<bits/stdc++.h>
using namespace std;
struct chazi
{
	int p,o,ca,da;
}b[100004];
int t,m=0;
long long n,sum[100004],sum1=0,q=0,jishu[4],a[100004][3],pshu[4],biaoji[100004];
bool cmp(chazi x,chazi y)
{
	if(x.o!=0&&y.o!=0)
	{
		return x.ca<=y.ca;
	}
	else{
		return x.p>=y.p;
	}
}
void bianli() 
{
	for(int r=1;r<=n;r++)
	{
		if(biaoji[r]==0)
		{
			if(m!=0)
			{
				for(int i=1;i<=n;i++)
				{
					if(b[r].da==b[r+i].da)
					{
						if(b[r+i].p>b[r].ca)
						{
						 	if(jishu[b[r+i].da]<q)
							{
								jishu[b[r+i].da]++;
								sum[r+i]=b[r+i].p;
								sum[r]=b[r].o;
								biaoji[r+i]++;
								break;
							}
							else{
								sum[r+i]=b[r+i].o;
								sum[r]=b[r].o;
								biaoji[r+i]++;
							}
						}
					}
					else{
							if(jishu[m]<q)
							{
								jishu[m]++;
								sum[r]=b[r].p;
							}
							else{
								sum[r]=b[r].o;
							}
						}
					
				}
			}
			else{
				sum[r]=b[r].p;
			}
			biaoji[r]++;
		}
	}
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		q=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(b[i].p<a[i][j])
				{
					b[i].p=a[i][j];
					b[i].da=j;
				}
			}
			pshu[b[i].da]++;
			for(int j=1;j<=3;j++)
			{
				if(b[i].p==a[i][j])
				{
					continue;
				}
				else{
					if(b[i].o<a[i][j]){
						
						b[i].o=a[i][j];
					}
				}
				b[i].ca=b[i].p-b[i].o;
			}	
		}
		sort(b+1,b+1+n,cmp);
		for(int j=1;j<=3;j++)
		{
			if(pshu[j]>q)
			{
				m=j;
			}
		}
		bianli();
		for(int i=1;i<=n;i++)
		{
			sum1+=sum[i];
		}
		cout<<sum1<<endl;
		for(int i=1;i<=n;i++)
		{
			b[i].p=0;
			b[i].o=0;
			b[i].ca=0;
			sum[i]=0;
		}
		for(int i=1;i<=3;i++)
		{
			pshu[i]=0;
		}
	} 
	fclose(stdin);
	fclose(stdout);
} 
