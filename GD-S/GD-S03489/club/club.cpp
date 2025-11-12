#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
long long int vis[maxn],n,m,t,a[4][maxn],ans;
void dfs(int x,long long int y){
	if(x==n+1){
		ans=max(ans,y);return;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]<(n/2)){
			vis[i]++;
			dfs(x+1,y+a[i][x]);
			vis[i]--;
		}
	}
}
void dfs2(int x,long long int y){
	if(x==n+1){
		ans=max(ans,y);return;
	}
	for(int i=1;i<=2;i++){
		if(vis[i]<(n/2)){
			vis[i]++;
			dfs(x+1,y+a[i][x]);
			vis[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int f1=0,f2=0;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]!=0)f1=1;
			if(a[3][i]!=0)f2=1;
		}
		ans=0;
		if(f1==0&&f2==0){
			sort(a[1]+1,a[1]+n+1);
			for(int i=n;i>n/2;i--){
				ans+=a[1][i];
			}
		}
		else if(f2==0||f1==0){
			dfs2(1,0);
		}
		else dfs(1,0);
		cout<<ans<<endl;
	}
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
