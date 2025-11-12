#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll a,b,c;
}s[100010];
ll f[100010][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		memset(f,0,sizeof(f));
		ll n,num,cna=1,cnb=1,cnc=1,maxn=-1;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&s[i].a,&s[i].b,&s[i].c);
		}
		num=n/2;
		f[1][1]=s[1].a,f[1][2]=s[1].b,f[1][3]=s[1].c;
		for(ll i=2;i<=n;i++)
		{
			for(ll j=1;j<=3;j++)
			{
				for(ll k=1;k<=3;k++)
				{
					if(k==1)
					{
						if(k==j)cna++;
						f[i][k]=f[i-1][j]+s[i].a;
						if(cna>num)f[i][k]=0;
					}								
					if(k==2)
					{
						if(k==j)cnb++;
						f[i][k]=f[i-1][j]+s[i].b;
						if(cnb>num)f[i][k]=0;
					}
					if(k==3) 
					{
						if(k==j)cnc++;
						f[i][k]=f[i-1][j]+s[i].c;
						if(cnc>num)f[i][k]=0;
					}
					//cout<<f[i][k]<<"  ";
					if(f[i][k]>maxn)maxn=f[i][k];
				}			
				//cout<<endl;
				cna--;
				cnb--;
				cnc--;
			}
			
		}
		printf("%lld\n",maxn);
	}
	return 0;
 } 
