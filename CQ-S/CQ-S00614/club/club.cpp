#include<bits/stdc++.h>
using namespace std;
int t,n,a[100002][3],sum[3],bh[100002],ans;
priority_queue<int,vector<int>,greater<int> > q;
signed main()
{
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>t;while(t--){
		cin>>n;for(int i=1;i<=n;++i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>a[i][1]) bh[i]=0;
			else bh[i]=1;if(a[i][bh[i]]<a[i][2]) bh[i]=2;
			++sum[bh[i]],ans+=a[i][bh[i]];
		}if(sum[0]>n/2){
			for(int i=1;i<=n;++i) if(bh[i]==0) q.push(a[i][0]-max(a[i][1],a[i][2]));
			for(int i=n/2,j;i<sum[0];++i) j=q.top(),q.pop(),ans-=j;
		}if(sum[1]>n/2){
			for(int i=1;i<=n;++i) if(bh[i]==1) q.push(a[i][1]-max(a[i][0],a[i][2]));
			for(int i=n/2,j;i<sum[1];++i) j=q.top(),q.pop(),ans-=j;
		}if(sum[2]>n/2){
			for(int i=1;i<=n;++i) if(bh[i]==2) q.push(a[i][2]-max(a[i][1],a[i][0]));
			for(int i=n/2,j;i<sum[2];++i) j=q.top(),q.pop(),ans-=j;
		}cout<<ans<<'\n',ans=sum[0]=sum[1]=sum[2]=0;
		while(!q.empty()) q.pop();
	}return 0;
}
