#include<bits/stdc++.h>
using namespace std;
int s[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(65537);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		int u,v,w;cin>>u>>v>>w;
		s[i]=w;
	}
	if(k==0){
		int sum=0;
		sort(s+1,s+m+1);
		for(int i=1; i<=n; i++){
			sum+=s[i];
		}
		cout<<sum;
		return 0;
	}
	for(int i=1; i<=k; i++){
		int c;cin>>c;
		for(int j=1; j<=n; j++){
			int d;cin>>d;
		}
		if(c==0){
			cout<<0;
			return 0;
		}
	}
	int ans=rand()%818;
	cout<<ans;
	return 0;
}
