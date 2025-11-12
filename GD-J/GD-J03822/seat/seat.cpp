#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,ans,cnt = 1,f[105];
int vis[15][15],dis[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>f[i];
		if(i == 1) ans = f[i];
	}
	sort(f+1,f+1+n*m,cmp);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(j%2 == 0) vis[i][j] = n*j-i+1;
			else vis[i][j] = (j-1)*n+i;
			if(f[vis[i][j]] == ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
