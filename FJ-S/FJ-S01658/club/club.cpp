#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N][3],cnt[3],ans,bl[N];
inline void sol()
{
	cin>>n;cnt[0]=cnt[1]=cnt[2]=ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int j=0;j<=2;j++) if(a[i][j]>=a[i][(j+1)%3]&&a[i][j]>=a[i][(j+2)%3])
		{bl[i]=j,ans+=a[i][j],cnt[j]++;break;}
	}
	int p=-1145;
	for(int i=0;i<=2;i++) if(cnt[i]>n/2) p=i;
	if(p==-1145) 
	{
		cout<<ans<<'\n';
		return;
	}
	priority_queue<int>pq;
	for(int i=1;i<=n;i++)
	{
		if(bl[i]!=p) continue;
		pq.push(max(a[i][(p+1)%3],a[i][(p+2)%3])-a[i][p]);
	}
	while(cnt[p]>n/2) cnt[p]--,ans+=pq.top(),pq.pop();
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--) sol();
}


