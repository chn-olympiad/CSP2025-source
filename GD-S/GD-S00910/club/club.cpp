#include<bits/stdc++.h>
using namespace std;
long long t,n,a[10005][4],b[10005][4],c[10005],e[10005],s,w[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		s=0;
		memset(w,0,sizeof(w));
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
			b[i][1]=a[i][1]-a[i][2];
			b[i][2]=a[i][2]-a[i][3];
			b[i][3]=a[i][3]-a[i][1];
			int d=-20005,z=0;
			for(int j=1;j<=3;j++)
			{
				if(d<b[i][j])
				{
					d=b[i][j];
					c[i]=j;
					z=1;
				}
				if(d<-b[i][j])
				{
					d=-b[i][j];
					if(j+1==4)c[i]=1;
					else c[i]=j+1;
					z=0;
				}
			}
			if(z)b[i][c[i]]=0;
			else if(c[i]-1==0)b[i][3]=0;
			else b[i][c[i]-1]=0;
			d=-20005,z=0;
			for(int j=1;j<=3;j++)
			{
				if(d<b[i][j])
				{
					d=b[i][j];
					e[i]=j;
					z=1;
				}
				if(d<-b[i][j])
				{
					d=-b[i][j];
					if(j+1==4)e[i]=1;
					else e[i]=j+1;
					z=0;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(w[c[i]]<=m)w[c[i]]++,s+=a[i][c[i]];
			else if(w[e[i]]<=m)w[e[i]]++,s+=a[i][e[i]];
			else
			{
				if(c[i]==1)
				{
					if(e[i]==2)w[3]++,s+=a[i][3];
					else if(e[i]==3)w[2]++,s+=a[i][2];
					else w[1]++;
				}
				if(c[i]==2)
				{
					if(e[i]==1)w[3]++,s+=a[i][3];
					else if(e[i]==3)w[1]++,s+=a[i][1];
					else w[2]++;
				}
				if(c[i]==3)
				{
					if(e[i]==2)w[1]++,s+=a[i][1];
					else if(e[i]==1)w[2]++,s+=a[i][2];
					else w[3]++;
				}
			}
		}
		cout<<s<<"\n";
	}
	return 0;
} 
