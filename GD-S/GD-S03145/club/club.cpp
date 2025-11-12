#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+10;
int t,n,a[N][4],c[4];
long long ans=0,d[4];
void dfs(int k){
	if(k>n){
		long long cnt=0;
		for(int i=1;i<=3;i++){
			cnt+=d[i];
		}
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(c[i]<n/2){
			c[i]++;
			d[i]+=a[k][i];
			dfs(k+1); 
			c[i]--;
			d[i]-=a[k][i];
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1);
		cout<<ans<<endl; 
	}
	return 0;
}

