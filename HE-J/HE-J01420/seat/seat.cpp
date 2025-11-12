#include<bits/stdc++.h>
using namespace std;
const int N=1010;

int n, m, q[N][N], s[N];
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};


int main(){
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	/*
	for(int i=0; i<=n*m; i++){
		cin>>s[N];
	}
	*/
	cin>>n>>m;
	int x=1, y=1, d;
	for(int i=0; i<=n*m; i++){
		q[x][y]=i;
		int c=x+dx[d];
		int r=y+dy[d];
		if(c<1 ||c>=n ||r<1 ||r>=m ||q[c][r]){
			
			d=(d+1)%4;
			c=x+dx[d];
			r=y+dy[d];
		}
		x=c, y=r;
		                    n;

	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cout<<q[i][j]<<" ";
		}
		cout<<endl;
	}
		
	return 0;
}
