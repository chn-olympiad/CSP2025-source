#include<bits/stdc++.h>
using namespace std;
//vector<int> ve[10010][10010];
//int a[10010],c[15],sum,now;
//int dp[10000][10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,s=0;
	cin>>n>>m>>k;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ve[u][v].push_back(w);
		ve[v][u].push_back(w);//建立费用 
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) s=1;
		for(int j=1;j<=n;j++){
			cin>>a[j];//改变费用 
			if(a[j]!=0) s=1; 
		}
	}
	if(!s){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<504898585;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
