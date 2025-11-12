#include <bits/stdc++.h>
using namespace std;
int t;
long long n,a[100005][5],ans,vis[5],cnt;
void sreach(int dep,int mem){
	if(dep==n) {
	ans=max(ans,cnt);
	return ;}
	for(int i=1;i<=3;i++)
		if(vis[i]<n/2)
		{vis[i]++;
		cnt+=a[mem][i];
		sreach(dep+1,mem+1);
		vis[i]--;
		cnt-=a[mem][i];
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		sreach(0,1);
		cout<<ans<<endl;
	}
	return 0;
}


