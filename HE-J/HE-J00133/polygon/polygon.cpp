#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[5005];
bool vis[5005];
bool dp[5005][5005];
int INF=998244353;
int dpp=0;
void cha(int step){
	
	for(int i=0;i<=dpp;i++){
		bool flag=false;
		for(int j=1;j<=step;j++){
			if(vis[j]!=dp[i][j]){
				flag=true;
			}
		}
		if(!flag) return ;
	}

	dpp++;
	cnt++;
	for(int i=1;i<=step;i++){
		dp[dpp][i]=vis[i];
	}

	return ;
}
void fid(int plus,int step,int maxx,int p){
	if(step>n) return ;
	if(p>=3&&plus>maxx*2) cha(step);
	for(int i=step;i<=n;i++){
		if(!vis[i]){
			fid(plus,step+1,maxx,p);
			vis[i]=true;
			fid(plus+a[i],step+1,max(maxx,a[i]),p+1);
			vis[i]=false;
		} 
	}

}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fid(0,1,0,0);
	cnt=cnt+1+INF%INF;
	cout<<cnt;
	return 0;
}
