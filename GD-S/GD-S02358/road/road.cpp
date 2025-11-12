#include <bits/stdc++.h>
using namespace std ; 
const int N = 1e3 +10 ; 
int road[N][N] ; 
//int tem[N][N] ; 
int a[N] ; 
int d[N] ; 
int tem[N]; //标记是否已连接 
int tot = 0 ;
int n, m , k ;
//vector<pair<int ,int >>ff ; 
long long zx(){
	d[1] = 0 ;
	long long ans = 0 ;
	int g = 1 ; 
	tem[g] = 1 ; 
	while(tot!=0){
		ans+=d[g] ;
//		cout <<g<<" "<<d[g]<<" "<<endl ; 
		tot-- ; 
		tem[g] = 1;
		int h  , minn = 0x3f3f3f3f;//h存编号，minn存距离 
		for(int i = 1 ; i<= n ; i++){
			if(!d[i]||d[i]>road[i][g]) d[i] = road[i][g] ; 
			if(!tem[i]&&d[i]<minn){
//				cout << i <<endl ;
				h = i ; 
				minn = d[i] ; 
			}
//			cout <<i <<" "<<d[i]<<endl;
		}
		g = h ; 
	}
	
	return ans ;
}

int main(){
	freopen("road.in" , "r",stdin) ; 
	freopen("road.out" , "w",stdout) ;
	ios::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	cout.tie(0) ; 
	cin >> n >> m >> k ;
	memset(d,0x3f,sizeof(d));
	memset(road , 0x3f , sizeof(road)) ; 
	for(int i = 1 ; i<=m ; i++){
		int x,y,z ; 
		cin>>x>>y>>z ; 
		road[x][y] = road[y][x] = min(z , road[y][x]) ; 
	}
	for(int i = 1 ;i <= k ; i++){
		int c ;
		cin >>c ;
		cin>>a[1] ;  
		for(int j = 2 ; j<= n ; j++){
			cin>>a[j] ; 
			for(int k = j-1 ; k>=1;k--){
				road[k][j] = road[j][k] = min(c+a[j] + a[k] , road[k][j]) ; 
			}
		}
	}
//	for(int i = 1 ; i<= n ; i++){
//		for(int j = 1 ;j <= n ; j++){
//			cout <<road[i][j]<<" ";
//		}
//		cout <<endl;
//	}
	tot = n ; 
	cout << zx() ;
	
	
	return 0;
}
