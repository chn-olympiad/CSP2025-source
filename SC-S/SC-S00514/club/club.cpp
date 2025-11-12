#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int h[4]={0,0,0,0};
int m;
int J[4][N],X,P[N],j=0,o=-1;
void dfs(int x,int sum){
	
	if(x==(m+1)){
		o=max(o,sum);
		return;
	}

	if(h[1]<X){
	
		h[1]++;
		dfs(x+1,(sum+J[1][x]));
		h[1]--;
	}
	if(h[2]<X){	

		h[2]++;
		dfs(x+1,(sum+J[2][x]));
		h[2]--;
	}
	if(h[3]<X){

		h[3]++;
		dfs(x+1,(sum+J[3][x]));
		h[3]--;
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		int G[4];
		int ans=0;
		for(int j=1;j<=m;j++){
			for(int z=1;z<=3;z++){
				cin>>J[z][j];
			}	
			int ma=max(J[1][j],max(J[2][j],J[3][j]));
			if(ma==J[1][j]){
				ans+=J[1][j];
				G[1]++;	
			}else if(ma==J[2][j]){
				ans+=J[2][j];
				G[2]++;	
			}else{
				ans+=J[3][j];
				G[3]++;
			}
		}
		X=(m/2);
		
		if(G[1]<=X&&G[2]<=X&&G[3]<=X){
			cout<<ans<<endl;
			G[1]=0;
			G[2]=0;
			G[3]=0;
			continue ;
		}else{
			dfs(1,0);
			cout<<o<<endl;
		
			o=-1;
		}
			G[1]=0;
			G[2]=0;
			G[3]=0;
	}
	
	return 0;
}