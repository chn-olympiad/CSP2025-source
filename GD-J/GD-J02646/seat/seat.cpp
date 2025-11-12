#include<bits/stdc++.h>
using namespace std;
bool cpp(int x,int y){
	return x>y;
}
	int p;
	int w=1;
	int m,n;
		int a,b;
int vis[101][101]={0};
void dfs(int x,int y,int u){
	if(u==p){
		w--;
		m=x;
		n=y;
		return;
	}
	
	vis[x][y]=1; 
	if(vis[x][y+1]==0&&y+1<=b){
		dfs(x,y+1,u+1);
		if(w==0){
		return;
	}
    }
    else if(vis[x][y-1]==0&&y-1>0){
	 	dfs(x,y-1,u+1);
		if(w==0){
		return;
	}
	}
	else if(vis[x+1][y]==0&&x+1<=a){
	 	dfs(x+1,y,u+1);
		if(w==0){
		return;
	}
	}
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	int c[101]={};
	int r;
	int len=a*b-1;
	for(int i=0;i<=len;i++){
		int u;
		cin>>u;
		c[i]=u;
		//cout<<u<<" ";
		if(i==0){
			r=u;
		}
	}
    // cout<<r<<" ";
	sort(c,c+len,cpp);
	for(int i=0;i<=len;i++){
		if(r==c[i]){
			p=i+1;
			break;
		}
	}
	//cout<<p<<" ";
	dfs(1,1,1);
	cout<<m<<" "<<n; 
	return 0;
}
