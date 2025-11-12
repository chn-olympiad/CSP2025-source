#include<bits/stdc++.h>
#define int long long
#define pir pair<int,int>
using namespace std;
const int N=1e5+5;
int T,n,ans,a[N][3],b[3];
priority_queue<int,vector<int>,greater<int> >q[3];
void solve()
{
	ans=0,b[0]=b[1]=b[2]=0;
	while(!q[0].empty())q[0].pop();
	while(!q[1].empty())q[1].pop();
	while(!q[2].empty())q[2].pop();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		int ma=0,mma=0,idx,idy;
		for(int j=0;j<=2;j++)
			if(a[i][j]>ma)mma=ma,ma=a[i][j],idy=idx,idx=j;
			else if(a[i][j]>mma)mma=a[i][j],idy=j;
		if(b[idx]<n/2)b[idx]++,ans+=ma,q[idx].push(ma-mma);
		else
		{
			if(q[idx].top()<ma-mma)ans=ans-q[idx].top()+ma,q[idx].pop(),q[idx].push(ma-mma);
			else b[idy]++,ans+=mma;
		}
//		cout<<ans<<'\n';
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)solve();
	return 0;
}
