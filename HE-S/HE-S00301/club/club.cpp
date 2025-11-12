#include<bits/stdc++.h>
using namespace std;
int t,n,m,my;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=1;x<=t;++x)
	{
		int a[10010]={0},b[10010]={0},c[10010]={0},d[10010]={0},e[100][100]={0,0},a1=0,b1=0,c1=0;
		my=0;
		cin>>n;
		for(int j=1;j<=n;++j)
		{
			cin>>a[j]>>b[j]>>c[j];
			if(m<a[j])
			{
				m=a[j];
			}
			else if(m<b[j])
			{
				m=b[j];
			}
			else if(m<c[j])
			{
				m=c[j];
			}
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		sort(c+1,c+n+1);
		for(int i=1;i<=n;++i)
		{
			if(a1<=n/2)
			{
				d[a[i]]+=1;
				e[i][1]=a[i];
			}
			if(b1<=n/2)
			{
				d[b[i]]+=1;
				e[i][2]=b[i];
			}
			if(c1<=n/2)
			{
				d[c[i]]+=1;
				e[i][3]=c[i];
			}
			if(e[i][1]>e[i][2]&&e[i][1]>e[i][3])
			{
				a1++;
			}
			else if(e[i][2]>e[i][1]&&e[i][2]>e[i][3])
			{
				b1++;
			} 
			else if(e[i][3]>e[i][1]&&e[i][3]>e[i][2]){
				c1++;
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(d[m]!=0)
			{
				my+=m;
				d[m]--;
				
			}
			else{
				while(d[m]==0)
				{
					m--;
				}
				my+=m;
				d[m]--;
			}
		}
		cout<<my<<endl;
	}
	return 0;
}
