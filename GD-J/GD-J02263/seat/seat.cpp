#include <bits/stdc++.h>
using namespace std;
/*
2 2
99 100 97 98
*/
/*
 2
3 1
 0
*/
int n,m;
int c,r;
int a[200];
int sit[20][20];
bool vis[20][20];
int stu;
int ex;
int cnt=1;
void dfs(int x,int y,int face){
	vis[x][y]=1;
	if(ex==0){
		sit[x][y]=a[1];
		return;
	}
	if(face==0){
//		cout<<"face:"<<face<<" ";
		if(x+1>=1&&x+1<=n&&y>=1&&y<=m&&vis[x+1][y]==0){
//			cout<<x+1<<" "<<y<<endl;
			vis[x+1][y]=1;
			sit[x+1][y]=a[ex];
			ex--;
			dfs(x+1,y,face);
		}
		else{
			dfs(x,y,1);
		}
	}
	if(face==1){
//		cout<<"face:"<<face<<" ";
		if(x==1){
			if(x>=1&&x<=n&&y+1>=1&&y+1<=m&&vis[x][y+1]==0){
//				cout<<x<<" "<<y+1<<endl;
				vis[x][y+1]=1;
				sit[x][y+1]=a[ex];
				ex--;
				dfs(x,y+1,0);
			}
		}
		else{
			if(x>=1&&x<=n&&y+1>=1&&y+1<=m&&vis[x][y+1]==0){
//				cout<<x<<" "<<y+1<<endl;
				vis[x][y+1]=1;
				sit[x][y+1]=a[ex];
				ex--;
				dfs(x,y+1,2);
			}
		}
	}
	if(face==2){
//		cout<<"face:"<<face<<" ";
		if(x-1>=1&&x-1<=n&&y>=1&&y<=m&&vis[x-1][y]==0){
//			cout<<x-1<<" "<<y<<endl;
			vis[x-1][y]=1;
			sit[x-1][y]=a[ex];
			ex--;
			dfs(x-1,y,face);
		}
		else{
			dfs(x,y,1);
		}
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	stu=a[1];
	sort(a+1,a+n*m+1);
	sit[1][1]=a[n*m];
	ex=n*m-1;
	dfs(1,1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(sit[i][j]==stu){
				cout<<j<<" "<<i<<'\n';
				return 0;
			}
		}
	}
	return 0;
}
