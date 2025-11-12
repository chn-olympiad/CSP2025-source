#include<bits/stdc++.h>
using namespace std;
int const N=1e5+10;

//struct node{
//	int a,b,c;
//}m[N];
int n,ans;
int m[N][5];

void dfs(int k,int x,int y,int z,int sum){
	if(k>n+1) return ;
	if(sum>ans) ans=sum;
	if(x!=0){
		dfs(k+1,x-1,y,z,sum+m[k][1]);
	}
	if(y!=0){
		dfs(k+1,x,y-1,z,sum+m[k][2]);
	}
	if(z!=0){
		dfs(k+1,x,y,z-1,sum+m[k][3]);
	}
}

void solve(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i][1]>>m[i][2]>>m[i][3];
		}
		ans=-1;
		dfs(1,n/2,n/2,n/2,0);
		cout<<ans<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	solve();  
	return 0;
}//awa
