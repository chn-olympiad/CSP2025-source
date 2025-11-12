#include<bits/stdc++.h>
using namespace std;

const int N=550;
int a[N], q[N][N];
int dx[3]={1, 0, -1};
int dy[3]={0, 1, 0};

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	
	int t=a[1];
	sort(a+1, a+n*m+1);

	int x=1, y=1, d=0;
	for(int i=1, j=n*m; i<=n*m; i++){
		q[x][y]=a[j--];
		
		int a=dx[d]+x;
		int b=dy[d]+y;
		if(a<1 || a>n || b<1 || b>m || q[a][b]){
			d=(d+1)%3;
			a=dx[d]+x;
			b=dy[d]+y;
		}
		x=a, y=b;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(q[i][j]==t){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
