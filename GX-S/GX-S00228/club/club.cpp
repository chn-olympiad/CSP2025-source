#include<iostream>
#include<bits/stdc++.h>
int maxn = 100100;
using namespace std;
void print(int m[100100][4], int p){
	for(int i = 1; i <= p; i++){
		for(int j = 1; j <= 3; j++) cout << m[i][j] << ' ';
		cout << endl;
	}
}
void sw(int& a, int&b){
	int c = 0;
	c = a;
	a = b;
	b = c;
}
void soort(int q[100100][4], int n, int R){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n;j++){
			if (q[j][R] < q[j+1][R]) sw(q[j][R],q[j + 1][R]);
			}
	}
	
}

int ans = 0;
int main(){
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	int t, n, A;//manyidu;
	int m[100100][4];
	memset(m, 0, 4);
	int q1[maxn][4];memset(q1, 0, maxn);
	int q2[maxn][4];memset(q2, 0, maxn);
	int q3[maxn][4];memset(q3, 0, maxn);
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		//int q1[maxn][4];memset(q1, 0, maxn);
		//int q2[maxn][4];memset(q2, 0, maxn);
		//int q3[maxn][4];memset(q3, 0, maxn);
		//int cnt[4];memset(cnt, 0, 3);
		for(int j = 1; j <= n; j++){
				for(int k = 1; k<= 3; k++){
					cin >> A;
					m[j][k] = A;
					q1[j][k] = A;
					q2[j][k] = A;
					q3[j][k] = A;
					//if (a > temp){
					//	cnt = k;
					//	temp = a;
					//}
					//m[cnt] += a;
					//for (int i = 1; i <= 3; i++) cout << m[i] << endl; 
					//printf("%d %d %d\n", a, cnt, temp);
					
				}
				
		}
		soort(q1, n, 1);
		for(int p = 1; p <= n/2; p++){ ans += q1[p][1]}
		
	}
	cout << ans;
	
	//cout << maax(1 ,2,3);
	
}
