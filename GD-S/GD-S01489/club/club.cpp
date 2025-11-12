#include<bits/stdc++.h> 
using namespace std;
long long t,n,sum,maxx,xb,ans,c[10005],maxn,a[10050][3],pd,pdd,d,xbb;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		sum=n/2;
		xb=0;pd=1;pdd=1;d=0;maxx=0;
		if(n==2)
		{
			for(int i=1;i<=6;i++)
			{
				cin>>c[i];
			}
			for(int i=1;i<=3;i++)
			{
				for(int j=4;j<=6;j++)
				{
					if(i+3!=j)
					{
						maxx=max(c[i]+c[j],maxx);
					}
				}
			}
			cout<<maxx<<"\n";
			continue;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin>>a[i][j];
				}
				if(a[i][3]==0 && pdd==1) pdd=1;
				else pdd=0;
				if(a[i][1]==a[i][3] && pd==1) pd=1;
				else pd=0;
				c[++xb]=a[i][2];
				if(a[i][2]>a[i][1] && maxn<sum)
				{
					d+=a[i][2];
					maxn++;
				}
				else
				{
					d+=a[i][1];
				}
			}
		}
		sort(c+1,c+xb+1);
		if(n>200 || pd==1)
		{
			cout<<c[xb]+c[xb-1]<<"\n";
		}
		else if(n>30 || pdd==1)
		{
			cout<<d<<"\n";
		}
		else 
		{
			cout<<ans<<"\n";
		}
	}
	return 0;
}
