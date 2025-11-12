#include <bits/stdc++.h>
using namespace std;
int a[100005][5];
int vis[5];
int n,ans=-1,line;
void dfs(int i,int sum){
	if(i>n){
		ans=max(ans,sum);
		return ;
	}
	for(int j=1;j<=3;j++){
		if(vis[j]<line){
			vis[j]++;
			dfs(i+1,sum+a[i][j]);
			vis[j]--;
		}
	}
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		line=n/2;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1,0);
		cout<<ans<<endl;
		ans=-1;
	}
	return 0;
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