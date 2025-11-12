#include<bits/stdc++.h>
using namespace std;
int long long t,n,x,y;
int long long ans,a[100005][5],c[100005],ansc,maxc;
int flaga;
int cmp(long long  p,long long q)
{
	return p>q;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		int long long ans=0,maxc=0,ansc=0;
		int flaga=1;
		memset(a,sizeof(a),0);
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0) flaga=0;
			maxc=max(a[i][1],a[i][2]);
			maxc=max(maxc,a[i][3]);
			ansc+=maxc;
		}
		if(flaga==1)
		{
			for(int i=1;i<=n;i++)
			{
				c[i]=a[i][1];
			}
			sort(c+1,c+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=c[i];
			}
		}
		else
		{
			ans=ansc;
		}
		cout<<ans<<endl;
	}
	return 0;
}
