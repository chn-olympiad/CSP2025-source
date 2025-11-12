#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[1001][1001],u,v,ans[100000000],sd=0,mk[11],w,i,j,b,c[1001],wk[11],cnt,rw[11][1001];

/*
int sort(){
	for(i=0;i<m;i++){
		for(j=0;j<m-i;j++){
			if(c[j]>c[j+1]){
				b=c[j];
				c[j]=c[j+1];
				c[j+1]=b;
			}
		}
	}
}
*/
void dfs(int x,int y,int min){
	if(x>n+k || y>n+k || x<0 || y<0){
		return;
	}
	if(a[x][y]<min){
		if(x<=n){
			min=a[x][y];
		}else{
			if(mk[x]!=1){
				if(wk[x]+a[x][y]<min){
					min=wk[x]+a[x][y];
					mk[x]=1;
					sd++;
					ans[sd]=min;
				}
			}
		}
	}
	dfs(x+1,y,min);
	dfs(x,y+1,min);
}
int main(){
	cin>>n>>m>>k;
	for(i=0;i<m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		c[i]=w;
	}
	for(i=0;i<k;i++){
		cin>>wk[i];
		for(j=0;j<n;j++){
			cin>>w;
			rw[i][j+1]=w;
			a[n+i+1][j+1]=w;
		}
	}
	dfs(1,1,100000);
	for(i=0;i<sd;i++){
		for(j=0;j<sd-i;j++){
			if(ans[j]>ans[j+1]){
				b=ans[j];
				ans[j]=ans[j+1];
				ans[j+1]=b;
			}
		}
	}
	for(i=0;i<n;i++){
		cnt=cnt+ans[i];
	}
	cout<<cnt;

	
	 
}
