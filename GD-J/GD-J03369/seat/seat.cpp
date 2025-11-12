#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m;
int a[N*N],seat[N][N];
bool vis[N][N];
int tot;
int fd;
queue<int> q;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	tot=n*m;
	for(int i=1;i<=tot;i++)
		cin>>a[i];
	fd=a[1];
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++)
		q.push(a[i]);
		
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			int cur=q.front();q.pop();
			if(j%2==0)seat[n-i+1][j]=cur;
			else seat[i][j]=cur;
		}
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(seat[i][j]==fd)
				cout<<j<<" "<<i;
	return 0;
}

