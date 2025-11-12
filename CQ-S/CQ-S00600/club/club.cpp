#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][5],id[N][5],sum[5];
void sol(){
	scanf("%d",&n);int ans=0;
	sum[0]=sum[1]=sum[2]=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		for(int j:{0,1,2})id[i][j]=j;
		sort(id[i],id[i]+3,[&](int x,int y){
			return a[i][x]>a[i][y];
		});
		// for(int j:{0,1,2})if(sum[id[i][j]]<n/2)
			sum[id[i][0]]++,ans+=a[i][id[i][0]];
	}
	int ts=max({sum[0],sum[1],sum[2]});
	if(ts>n/2){
		int t;
		if(ts==sum[0])t=0;
		if(ts==sum[1])t=1;
		if(ts==sum[2])t=2;
		vector<int>ve;
		for(int i=1;i<=n;i++)if(id[i][0]==t)
			ve.push_back(a[i][t]-a[i][id[i][1]]);
		sort(ve.begin(),ve.end());
		for(int i=0;i<ts-n/2;i++)ans-=ve[i];
	}
	printf("%d\n",ans);
}
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--)sol();
	return 0;
}