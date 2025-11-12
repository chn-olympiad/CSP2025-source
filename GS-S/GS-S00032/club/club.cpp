#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200+10;
ll n,num[5][N],sum[5],du=0,s;
int T;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int u=1;u<=T;u++)
	{
		memset(num,0,sizeof(num));
		memset(num,0,sizeof(sum));
		pair<ll,ll> c[5][N];
		cin>>n;
		du=n/2;
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=3;j++) 
			{
				cin>>num[i][j];
				c[i][j].second=num[i][j];
				c[i][j].first=j;
			}
			for(int o=1;o<=n;o++)
			{
				for(int k=1;k<=3;k++) 
				{
					if(c[i][k].second<=c[i][k+1].second)
					{
					 	swap(c[i][k].first,c[i][k+1].first);
						swap(c[i][k].second,c[i][k+1].second);
					} 
				}
			}
		} 
		for(int o=1;o<=n;o++)
		{
			for(int k=1;k<=3;k++) 
		    {
			    if(c[k][1].second<=c[k+1][1].second)
				{
					swap(c[k][1].first,c[k+1][1].first);
				    swap(c[k][1].second,c[k+1][1].second);
				} 
			}
		}
		for(int i=1;i<=n;i++) 
		{
			if(sum[c[i][1].first]<=du) s+=c[i][1].second,sum[c[i][1].first]++;
			else
			{
				if(sum[c[i][2].first]<=du) s+=c[i][2].second,sum[c[i][2].first]++;
				else  s+=c[i][2].second,sum[c[i][2].first]++;
			} 
		}
		cout<<s<<endl;
		s=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
