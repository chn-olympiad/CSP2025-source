#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,c[200005];
unsigned int a[200005],b[200005],u=1e9+7,t[5000005],aa[5000005],bb[5000005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
   cin>>n>>q;
   t[0]=1;
   for(register int i=1;i<=5000000;i++)t[i]=(t[i-1]*u);
   for(register int i=1;i<=n;i++)
   {
   	   string h;
   	   cin>>h;
   	   c[i]=h.size();
   	   unsigned int tt=0;
   	   for(int j=0;j<h.size();j++)
   	   {
   	   	  tt*=u;
   	   	  tt+=h[j];
	   }
	   a[i]=tt;
	   tt=0;
	   cin>>h;
	   for(register int j=0;j<h.size();j++)
   	   {
   	   	  tt*=u;
   	   	  tt+=h[j];
	   }
	   b[i]=tt;
   }
   
   while(q--)
   {
   	   string x,y;
   	   cin>>x>>y;
   	   register int m=x.size();
   	   unsigned int tt=0;
   	   for(int i=0;i<m;i++)
   	   {
   	   	   aa[i+1]=aa[i]*u+x[i];
	   }
	   register int s=0;
	   for(register int i=0;i<m;i++)bb[i+1]=bb[i]*u+y[i];
		for(register int i=1;i<=n;i++)
		{
			register int nn=c[i];
			for(register int j=0;j<m-nn+1;j++)
			{
				if(aa[j]*t[nn]+a[i]==aa[j+nn])
				{
					register int u=aa[j]*t[nn]+b[i];
					register int o=j+nn;
					if(u*t[m-o]+aa[m]-aa[o]*t[m-o]==bb[m])
					{
						s++;
						break;
					}
				}
			}
		}
		cout<<s<<"\n";	   
   }
   return 0;
}

