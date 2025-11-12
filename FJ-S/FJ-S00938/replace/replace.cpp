#include<bits/stdc++.h>
using namespace std;
long long n,m,cc[500100],dd[500100];
string a[500100],b[501000];
main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		long long u=a[i].size();
		cc[i]=u;dd[i]=-1;
		for(long long j=0;j<u;j++)
		if(a[i][j]!=b[i][j])
			cc[i]=min(cc[i],j),dd[i]=max(dd[i],j);
	}
	for(long long i=1;i<=m;i++)
	{
		long long s=0;
		string c,d;
		cin>>c>>d;
		long long v=c.size();
		long long l=v,r=-1;
		for(long long j=0;j<v;j++)
		if(c[j]!=d[j])
			l=min(l,j),r=max(r,j);
			
		for(long long j=1;j<=n;j++)
		{
			long long u=a[j].size();
			if(l>=cc[j]&&u-r<=v-dd[j]&&r-l==dd[j]-cc[j])
			{
				bool pan=true;
				for(long long k=l,q=cc[j];k<=r&&pan;k++,q++)
					if(a[j][q]!=c[k]||b[j][q]!=d[k])
						pan=false;
				for(long long k=r+1,q=dd[j]+1;q<u&&pan;k++,q++)
					if(a[j][q]!=c[k]||b[j][q]!=d[k])
						pan=false;
				for(long long k=l,q=cc[j];k>=0&&pan;k--,q--)
					if(a[j][q]!=c[k]||b[j][q]!=d[k])
						pan=false;
				s=s+pan;
			}
		}
		printf("%lld\n",s);
	}
}
