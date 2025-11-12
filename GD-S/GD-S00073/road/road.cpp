#include<bits/stdc++.h>

using namespace std;

int n,m,k,maps[10110][10110],a,b,w,c[11],res[10110][10110],resu;
struct Wy{
	int a,b;
}dp[10110];

int main(){
	freopen("road1.in","r",stdin);
	freopen("road.txt","w",stdout);
	cin>>n>>m>>k;
	memset(maps,0x3f3f3f3f,sizeof(maps));
	for(int i = 1;i<=m;i++){
		cin>>a>>b>>w;
		maps[a][b] = w;
		maps[b][a] = w;
	}
	for(int i =n+1;i<n+1+k;i++){
		cin>>c[i-n];
		for(int j = 0;j<n;j++){
			cin>>maps[j][i];
			maps[i][j] = maps[j][i];
		}
	}
	for(int i = 1;i<=n;i++){
		dp[i].a = maps[1][i];
		dp[i].b = 1*10+i;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int z =2;z<=n;z++){
				if(maps[z][j]+dp[z].a<dp[j].a){
					dp[j].a =maps[z][j]+dp[z].a;
					dp[j].b = dp[z].b*10+j;
				}
			}
		}
	}
	for(int i = 1;i<=n;i++){
		int head =dp[i].b%10;
		dp[i].b/=10;
		while(dp[i].b>0){
			res[head][dp[i].b%10] =1;
			head = dp[i].b%10;
			dp[i].b/=10;
		}
	}
	for(int i =1;i<= n-1;i++){
		for(int j = i+2;j<=n;j++){
			if(res[i][j] ==1) resu+=maps[i][j];
		}
	}
	cout<<resu;
}
