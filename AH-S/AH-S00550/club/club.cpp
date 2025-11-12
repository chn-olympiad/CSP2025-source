#include<bits/stdc++.h>
using namespace std;

int tt,n,p[100005][5],maxx;
void dfs(int t,int a,int b,int c,int sum){
	if(t==n+1){
		if(a<=n/2 && b<=n/2 && c<=n/2){
			maxx=max(maxx,sum);
		}
		return;
	}
	dfs(t+1,a+1,b,c,sum+p[t][1]);
	dfs(t+1,a,b+1,c,sum+p[t][2]);
	dfs(t+1,a,b,c+1,sum+p[t][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> tt;
	for(int q=1;q<=tt;q++){
		maxx=-1;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> p[i][1] >> p[i][2] >> p[i][3];
		}
		dfs(1,0,0,0,0);
		cout << maxx << endl;
	}
	return 0;
}
