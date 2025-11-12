#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],mx[N],prf[N],pop[4],rec[4][N],xx,ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>mx[i])
			{
				mx[i]=a[i][j];
				prf[i]=j;
			}
		}
		pop[prf[i]]++;
		sort(a[i]+1,a[i]+1+3);
		rec[prf[i]][pop[prf[i]]]=a[i][3]-a[i][2];
//		cout<<prf[i]<<' '<<mx[i]<<' '<<rec[i]<<'\n';
		ans+=mx[i];
	}
	for(int j=1;j<=3;j++)
		if(pop[j]>=n/2) xx=j;
//	cout<<pop[1]<<' '<<pop[2]<<' '<<pop[3]<<'\n';
//	cout<<xx<<' '<<pop[xx]<<'\n';
	sort(rec[xx]+1,rec[xx]+1+pop[xx]);
//	cout<<ans<<' '<<pop[xx]-n/2<<'\n';
	for(int i=1;i<=pop[xx]-n/2;i++)
		ans-=rec[xx][i];
	cout<<ans<<'\n';
//	cout<<'\n';//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for(int i=1;i<=n;i++) mx[i]=0,prf[i]=1;
	pop[1]=pop[2]=pop[3]=ans=0; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--) solve();
}
