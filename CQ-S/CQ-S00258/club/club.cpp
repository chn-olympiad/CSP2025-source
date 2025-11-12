#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][3],ans,nm[3],b[N][3],c[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n,ans=nm[0]=nm[1]=nm[2]=0;
		for(int x,i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++) cin>>a[i][j];x=max(max(a[i][0],a[i][1]),a[i][2]),ans+=x;
			for(int j=0;j<3;j++) if(a[i][j]==x){b[++nm[j]][j]=i;break;}
		}
		for(int i=0;i<3;i++)
		{
			if(nm[i]<=n/2) continue;
			for(int j=1;j<=nm[i];j++)
			{
				int w=b[j][i],x=a[w][0],y=a[w][1],z=a[w][2];
				if(!i) swap(x,y);if(i<2) swap(y,z);
				c[j]=z-max(x,y);
			}
			sort(c+1,c+nm[i]+1);
			for(int j=1;j<=nm[i]-(n/2);j++) ans-=c[j];break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
