#include <bits/stdc++.h>
using namespace std;

long long n,m,a[150][150];
long long b[1000005];
int cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int k = 1;
	
	for(long long i = 1;i <= n;i ++){
		for(long long j = 1;j <= m;j ++){
			cin >> a[i][j];
			b[k]=a[i][j];
			k ++;
		}
	}
	int ans = a[1][1];
	sort(b+1,b+k+1,cmp);
	long long l = 1;
	for(long long i = 1;i <= n;i ++){
		if(i % 2 == 1){
		for(long long j = 1;j <= m;j ++){
				a[j][i] = b[l];
				l ++;
			}
		}
		if(i % 2 == 0){
			for(long long j = m;j >= 1;j --){
				a[j][i] = b[l];
				l ++;			
			}
		}
	}
	
	for(long long i = 1;i <= n;i ++){
		for(long long j = 1;j <= m;j ++){
			if(a[i][j] == ans){
				cout << j << " " << i;
			}
		}
	}
	
	
	return 0;
} 
