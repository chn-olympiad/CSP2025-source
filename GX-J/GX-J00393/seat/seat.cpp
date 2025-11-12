#include<bits/stdc++.h>
using namespace std;
int n,m,score=0;
int ans[110];
int v=1;
int mp[11][11];
bool flag[110];
bool bf(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ans[i];
	}
	score=ans[1];
	sort(ans+1,ans+n*m+1,bf);
	
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			flag[i]=true;
		}
	}
	for(int i=1;i<=m;i++){
		if(flag[i]==1){
			for(int j=1;j<=n;j++){
				
				mp[i][j]=ans[v];
				v++;
			}
		}else{
			for(int j=n;j>=1;j--){
				mp[i][j]=ans[v];
				v++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(score==mp[i][j]) cout<<i<<' '<<j;
		}
	}
	return 0;
}
