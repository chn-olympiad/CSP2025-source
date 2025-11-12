#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,m,k,a[N][4],b[10][N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	long long sum = 0,mx = -1,sum2 = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		sum+=a[i][1]+a[i][2]+a[i][3];
	}
	for(int i = 1;i <= k;i++){
		for(int j =1;j <= n+1;j++){
			cin >> b[i][j];
			sum2+=b[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 3;j++){
			if(a[i][j] > mx){
				if(mx == -1){
					mx = a[i][j];
					sum-=mx;
				}else{
					sum+=mx;
					mx = a[i][j];
					sum-=mx;
				}
			}
		}
	}
	bool f = false;
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n+1;j++){
			if(b[i][j] > mx && !f){
				sum+=mx;
				mx = b[i][j];
				sum2-=b[i][j];
				f = true;
			}else if(b[i][j] > mx && true){
				sum2+=mx;
				mx = b[i][j];
				sum2-=mx;
			}
		}
	}
	sum+=k*sum2-n-m-k;
	cout << mx-sum;
	return 0;
}
