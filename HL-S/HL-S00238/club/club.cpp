#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
int a[maxn][3];
int vis[maxn][3];
int d[5][2]={{-2,-1},{-1,-1},{0,-1},{1,-1},{2,-1}};
int t;
struct node{
	int x;
	int y;
	int m;
}q[maxn*3];
int bfs(int x,int y,int z){
	int head=1;
	int tail=1;
	q[tail].x=x;
	q[tail].y=y;
	q[tail].m=a[0][0];
	tail++;
	while(head>tail){
		int x0=q[head].x;
		int y0=q[head].y;
		int m=q[tail].m;
		vis[x0][y0]=1;
		for(int i=0;i<5;i++){
			int nx=x0+d[i][0];
			int ny=y0+d[i][1];
			if(q[tail].y==z){
				return q[tail].m;
			}
			if(nx>0 && nx<z && ny>0 && ny<2 && vis[nx][ny]!=1){
				q[tail].x=nx;
				q[tail].y=ny;
				q[tail].m=m+a[nx][ny];
				vis[nx][ny]=1;
				tail++;
			}
		}
		head++;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k];
			}
		}	
		cout<<bfs(0,0,n-1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}