#include<bits/stdc++.h>
using namespace std;
int a[10000000];
bool b[5000][5000];
int fy[5]={0,-1,1};
int n,m;
void dfs(int x,int y,int c,int j){
	if(j==c){
		cout<<x<<" "<<y;
		return;
	}
	if(y==n&&b[y-1][x]==1){
		x++;
		j++;
		b[y][x]=1;
	}if(y==1&&b[y+1][x]==1){
		x++;
		j++;
		b[y][x]=1;
	}
	if(j==c){
		cout<<x<<" "<<y;
		return;
	}
	for(int i=1;i<=2;i++){
		int ty=y+fy[i];
		if(ty<=n&&ty>=1&&b[ty][x]==0){
			b[ty][x]=1;
			dfs(x,ty,c,j+1);
			break;
		}
	}
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int k=a[1],s=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=0;
		}
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
			s=n*m-i+1;
			break;
		}
	}b[1][1]=1;
	dfs(1,1,s,1);
    return 0;
}
