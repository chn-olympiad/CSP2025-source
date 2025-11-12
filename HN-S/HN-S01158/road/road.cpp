#include<bits/stdc++.h>
using namespace std;
int n,m,k,r[8000][8000],sum,qd,zd,ans,f[15],ff[15][10005];
bool flag[10005]; 
void dfs(int a,int b){//起点为a经过b个点 
	if(b==n){
		if(ans==0){
			ans=sum;
			return;
		}
		else{
			ans=min(ans,sum);
			return;
		} 
	}
	else{
		for(int i=1;i<=n;i++){
			if(r[a][i]!=0){ 
				if(!flag[i]){
					flag[i]=1;
					sum+=r[a][i];
					dfs(i,b+1);
					flag[i]=0;
					sum-=r[a][i];
				}
			}	
		}
	}
}
int main(){
	freopen("road1.in","r",stdin);
	freopen("road1.out","w",stdout);
	cin>>n>>m>>k;	
	for(int i=1;i<=m;i++){
		cin>>qd>>zd;
		cin>>r[qd][zd];
		r[zd][qd]=r[qd][zd];
		
	}
	for(int i=1;i<=k;i++){
		cin>>f[i];
		for(int j=1;j<=n;j++){
			cin>>ff[i][j];
		}
	}	
	
	flag[1]=1;
	dfs(1,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

