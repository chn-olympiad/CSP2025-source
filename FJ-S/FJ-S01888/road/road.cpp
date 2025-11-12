#include<bits/stdc++.h>

using namespace std;

long long a[5][1100005],b[10005],ans=0x3f3f3f3f3f3f3f3f;
bool flag[10015];
int k,m,n;

void dfs(int x,long long sum){
	if(x>=n-1){
		for(int i=1;i<=n;i++){
			if(!flag[i]){
				return;
			}
		}
		ans=min(ans,sum);
		return;
	}
	flag[a[1][x]]=flag[a[2][x]]=1;
	dfs(x+1,sum+a[3][x]);
	flag[a[1][x]]=flag[a[2][x]]=0;
	dfs(x+1,sum);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[1][i]>>a[2][i]>>a[3][i];//u,v,w
	}
	int b;
	for(int i=m+1;i<=m+k;i++){
		cin>>b;
		for(int j=1;j<=n;j++){
			a[1][i]=0;
			a[2][i]=j;
			cin>>a[3][i];
			a[3][i]+=b;
		}
	}
	dfs(1,0);
	cout<<ans;
	
	return 0;
}
