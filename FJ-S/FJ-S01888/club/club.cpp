#include<bits/stdc++.h>

using namespace std;

int f[5][100005];
int a[5],n,ans;

void dfs(int x,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(a[i]==n/2){
			continue;
		}
		a[i]++;
	//	cout<<x<<" "<<i<<" "<<a[i]<<" "<<f[i][x]<<endl;
		dfs(x+1,sum+f[i][x]);
		a[i]--;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	
	while(t--){
		memset(a,sizeof(a),0);
		ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>f[1][i]>>f[2][i]>>f[3][i];
		}
		dfs(1,0);
		if(!t){
			cout<<ans;
		}
		else{
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
