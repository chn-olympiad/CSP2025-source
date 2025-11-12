#include<bits/stdc++.h>
using namespace std;
int a[10010][10010];
int b[10];
int c[10][10100]; 
int ans[10010];
queue <int> q;
int F[10010];
int f[10010];
int find(int x){
	if(F[x]==x){
		return x;
	}
	return find(F[x]);
}
int main() {
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		a[x][y]=a[y][x]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n+1;j++){
			cin>>c[i][j];	
	}
}
	q.push(1);
	ans[1]=0;
	F[1]=1;
	memset(ans+1,sizeof(ans),1e9);
	int cnt;
	while(!q.empty()){
		int num=q.front();
		for(int i=1;i<=n;i++){
			if(a[num][i]>0&&F[i]!=F[num]){
				ans[i]=ans[num]+a[num][i];
				F[i]=find(num);
				q.push(i);
				cnt++;
			}else if(a[num][i]>0){
				ans[i]=min(ans[i],ans[num]+a[num][i]);				
			}
		}
		if(cnt==n-1) cout <<ans[num];
		q.pop();
	}
	
	return 0;
}

