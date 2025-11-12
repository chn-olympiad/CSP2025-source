#include<bits/stdc++.h>
using namespace std;


const int N = 210;
typedef long long LL;
typedef pair<int, int> PII;

int a[N][5];
int f[N][N][N]; 
/*
状态定义
 // f[i][j][k][l]表示考虑到第i个人，部门a容纳j个人，b部门k个人.....的最大满意值
 // 最大值
 // f[i][j][k][l] = max([j - 1], [k - 1], [l - 1]) 
*/ 

int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin>>T;
	while(T --){
		
		int n, m;
		cin>>n;
		m = n / 2;
		for(int i = 1 ; i <= n ; i ++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		
		memset(f, 0, sizeof f);
		for(int i = 1 ; i <= n ; i ++){
			for(int j = m ; j >= 0 ; j --){
				for(int k = m ; k >= 0 ; k --){
					for(int l = m ; l >= 0 ; l --){
						if(j > 0) f[j][k][l] = max(f[j - 1][k][l] + a[i][1], f[j][k][l]);
						if(k > 0) f[j][k][l] = max(f[j][k - 1][l] + a[i][2], f[j][k][l]);
						if(l > 0) f[j][k][l] = max(f[j][k][l - 1] + a[i][3], f[j][k][l]);
					}
				}
			}
		}	
		cout<<f[m][m][m]<<'\n';
	} 
	
	/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
	*/
	return 0;
}
