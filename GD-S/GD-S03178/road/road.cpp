#include<bits/stdc++.h>
using namespace std;
long long n,m,k,r[10009][10009],rr[10009],dp[10009][10009];
struct node{
	long long u,v,f,b;
}rd[10009];
dfs(int nn){
	for(int j=1;j<=n;j++){
		for(int i=1;i<=rr[n];i++){
		    if(rd[dp[j][rd[nn][i].u]].f>rd[dp[j][nn]].f+rd[r[nn][i]].f)
	}
	}
}
int main(){
	cin>>n>>m>>k;
	memset(dp,1000000009,sizeof(dp));
	for(int i=1;i<=m;i++){
		int a1,a2,a3;
		cin>>a1>>a2>>a3;
		rr[a1]++;
		rr[a2]++;
		rd[i].f=a3;
		r[a1][rr[a1]]=i;
		r[a2][rr[a2]]=i;
		
	}
} 
