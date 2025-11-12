#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b) {
	return a>b;
}
int arr[15][15];
bool flag[15][15];
int xps[4]= {0,1,0,-1};
int yps[4]= {-1,0,1,0};
int ji[100001];
int dfs(int x,int y,int num,int cum) {
	if(num==cum) return 0;
	for(int i=0; i<4; i++) {
		int nx=x+xps[i];
		int ny=y+yps[i];
		if(flag[nx][ny]!=1 && nx<n && nx>=0 && ny<m && ny>=0) {
			arr[x][y]=ji[num];
			flag[x][y]=1;
			dfs(nx,ny,num++,cum);
		}
	}
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int b=n*m;
	for(int i=0; i<b; i++) {
		cin>>ji[i];
	}
	long long s=ji[0];
	long long cum;
	sort(ji,ji+b,cmp);
	for(int i=0; i<b; i++) {
		if(ji[i]==s) cum=i;
//		cout<<ji[i]<<" ";
	}
	long long x=0,y=0;
	long long num=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout<<arr[i][j]<<" ";
		}
	}
	return 0;
}
