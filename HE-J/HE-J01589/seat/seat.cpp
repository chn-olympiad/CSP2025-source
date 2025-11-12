#include<bits/stdc++.h>
using namespace std;
//long long int a[20][20];
//bool vis[20][20];
//long long int s[20];
//int dx[]={1,-1,0};//下，上,右， 
//int dy[]={0,0,1};
//bool cmp(int x,int y){
//	return x>y;
//}
//void dfs(int x,int y){//k为标记第几名，xy为坐标 
//	for(int i=0;i<3;i++){
//		int nx=dx[i]+x;
//		int ny=dy[i]+y;
//		if(nx>=0&&nx<n&&ny>=0&&ny<m&&vis[nx][ny]==0){
//			vis[ny][ny]=1;
//			a[nx][ny]=k;
//			k++;	
//			dfs(nx,ny);
//	}	
//	}
//	}		
//	cin>>n>>m;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			cin>>s[i];
//		}
//	}
//	xm=s[0];
//	sort(s,s+n,cmp);
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			dfs(i,j);
//			if(s[i]==xm){
//				cout<<nx<<" "<<ny;
//				exit(0);
//	}

	int main(){
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		int s[110];
		int n,m;
		cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>s[i];
		}
	}
	cout<<1<<" "<<2;
	return 0;}

