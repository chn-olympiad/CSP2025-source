#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
long long midn;//n/2
int a[N][5];
long long ans=-1;//最大满意度,当前最大满意度 
bool vis[N];

void dfs(long long mid,long long x,long long dj,long long ren1,long long ren2){
	if(ren2==n){
		ans=max(ans,dj);
		return ;
	}

	if(ren1+1>mid){
		dfs(mid,x+1,dj,0,ren2);
	}
	
	for(int i=1;i<=n;i++){
		if(ren1+1<=mid&&ren2+1<=n&&vis[i]==false){
			vis[i]=true;
			
			dfs(mid,x,dj+a[i][x],ren1+1,ren2+1);
			dfs(mid,x+1,dj+a[i][x],ren1+1,ren2+1);
			
			vis[i]=false;
		}
			
	}
	
	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		midn=n/2;
		for(int j=1;j<=n;j++){
			vis[j]=false;
		}
		ans=-1;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		
		dfs(midn,1,0,0,0);
		printf("%d\n",ans);
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

