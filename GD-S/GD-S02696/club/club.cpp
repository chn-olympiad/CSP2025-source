#include<bits/stdc++.h>
using namespace std;
int a[20001][5],b[20001][5],c[20001][5],d[1001][1001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=10000;i++)
		{
			for(int j=1;j<=3;j++)
			{
				a[i][j]=0;
				b[i][j]=0;
				c[i][j]=0;
			}
		}
		for(int i=1;i<=1000;i++)
		{
			for(int j=1;j<=1000;j++)
			{
				d[i][j]=0;
			}
		}
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				b[i][j]=j;
			}
			for(int j=1;j<3;j++)
			{
				if(a[i][j]<a[i][j+1]&&b[i][j]<b[i][j+1])
				{
					swap(b[i][j],b[i][j+1]);
				}
				if(j!=1)
				{
					if(a[i][j]<a[i][j-1]&&b[i][j]<b[i][j-1])
					{
						swap(b[i][j],b[i][j-1]);
					}
				}
				if(a[i][j]<a[i][j+2]&&j+2<=n&&b[i][j]<b[i][j+2])
				{
					swap(b[i][j],b[i][j+2]);
				}
				
			}
			for(int j=1;j<=3;j++)
			{
				c[i][b[i][j]]=j;
			}
		}
		int t[10],maxt=-1,maxi;
		t[1]=1;
		t[2]=1;
		t[3]=1;
		for(int i=1;i<=n;i++)
		{
			int pos=c[i][1];
			d[pos][t[pos]]=i;
			t[pos]++;
			if(t[pos]-1>maxt)
			{
				maxt=t[pos]-1;
				maxi=pos;
			}
		}
		int ans=0;
		if(maxt<=n/2)
		{
			for(int i=1;i<=n;i++)
			{
				ans+=a[i][c[i][1]];
			}
			cout<<ans<<endl;
		}
		else{
			int mina=INT_MAX,mini;
			while(maxt>n/2){
				mina=INT_MAX;
				if(maxt<=n/2)break;
				for(int i=1;i<=t[maxi];i++)
				{
					if(maxt<=n/2)break;
					if(d[maxi][i]==0)continue;
					if(a[d[maxi][i]][c[d[maxi][i]][1]]==a[d[maxi][i]][c[d[maxi][i]][2]])
					{
						maxt--;
						swap(c[d[maxi][i]][1],c[d[maxi][i]][2]);
						d[maxi][i]=0;
					}
					else
					{
						if(mina>a[d[maxi][i]][c[d[maxi][i]][1]]-a[d[maxi][i]][c[d[maxi][i]][2]])
						{
							mina=a[d[maxi][i]][c[d[maxi][i]][1]]-a[d[maxi][i]][c[d[maxi][i]][2]];
							mini=i;
						}
					}
					if(maxt<=n/2)break;
				}
				if(maxt<=n/2)break;
				swap(c[d[maxi][mini]][1],c[d[maxi][mini]][2]);
				d[maxi][mini]=0;
				maxt--;
				if(maxt<=n/2)break;
			}	
			for(int i=1;i<=n;i++)
			{
				ans+=a[i][c[i][1]];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
