//GZ-S00392 贵阳市第一中学 蒋旻昊 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b[N],ans,jp[3],c[N],p[N],pp,d[N],n,T,sd[N],md[N];
int main()
{	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

		ans=0;
		pp=0;
		jp[1]=0;
		jp[2]=0;
		jp[3]=0;
		cin>>n;
		int o=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			o++;
			d[o]=a[i];
			sd[o]=i;
			md[o]=1;
			o++;
			d[o]=b[i];
			sd[o]=i;
			md[o]=2;
			o++;
			d[o]=c[i];
			sd[o]=i;
			md[o]=3;
		}
		for(int i=1;i<=3*n;i++)
		{
			for(int j=i;j<=3*n;j++)
			{
				if(d[j]>d[i])
				{
					swap(d[j],d[i]);
					swap(sd[j],sd[i]);
					swap(md[j],md[i]);
				}
			}
		}
		for(int i=1;i<=3*n;i++)
		{
				int y=n/2;
			if(p[sd[i]]==0&&jp[md[i]]<y)
			{
				p[sd[i]]=1;
				ans+=d[i];
				pp++;
				jp[md[i]]++;
				
			}
			else if(pp==n)
			{
			
				break;
			}
		}
		for(int i=1;i<=3*n;i++)
		{
			p[i]=0;
		}
		cout<<ans<<endl;
	
}
