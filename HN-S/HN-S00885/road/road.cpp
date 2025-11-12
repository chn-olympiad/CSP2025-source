#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+3;
int n,m,k,intol=0;
struct node{
	int c1,c2,c;
	bool q=0;
}a[10005];
queue<node> q;
int dfs(int sumn,int c1,int c2,int c){
	for(int i=1;i<=n;i++){
		q.push({c1,c2,c});
		a[i].q = 1;
		while(!q.empty()){
			
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ck[12][n+5];
	bool s[10005] ={0};
	for(int i=1;i<=n;i++){
	cin>>a[i].c1>>a[i].c2>>a[i].c;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>ck[i][j];
			ck[i][n+2] += ck[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		dfs(0,a[i].c1,a[i].c2,a[i].c);
	}
	return 0;
}
