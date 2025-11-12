#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[15][15],s[101],t,fev;
bool c[15][15];
int tx[4]={0,-1,0,1},ty[4]={1,0,-1,0};
void dfs(int h,int target,int x,int y){
	h++;
	if(h==target){
		printf("%d %d",x+1,y+1);
		return;
	}
	c[x][y]=false;
	for(int i=0;i<4;i++){
		if(c[x+tx[i]][y+ty[i]]==true){
			dfs(h,target,x+tx[i],y+ty[i]);
			break;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c[i][j]=true;
		}
	}
	for(int i=0;i<n*m;i++){
		int b;
		cin>>b;
		if(i==0){
			fev=b;
		}
		s[b]++;
	}
	for(int i=100;i>fev;i--){
		t+=s[i];
	}
	dfs(0,t+1,0,0);
	return 0;
}
