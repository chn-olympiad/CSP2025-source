#include <bits/stdc++.h>
using namespace std;
const unsigned long long N = 1e4+3;
long long t,n,a[N][N];
bool v[N];
long long ans;
struct intt{
	long long value;
	long long num;
};
bool cmp(intt a, intt b){
	return a.value > b.value;
}
bool cmpp(long long a, long long b){
	return a > b;
}
//int b(int n){
//	vector<intt> x; 
//	int s = 0;
//	for(int i = 1; i <= n; i++){
//		if(a[i][1]>=a[i][2]){
//			x.push_back({a[i][1],i});
//		}
//		v[i] = false;
//	}
//	sort(x.begin(),x.end(),cmp);
//
//	for(int i = 0; i < n/2; i++){
//		s+=x[i].value;
//		cout << x[i].value << " " << x[i].num<< endl;
//		v[x[i].num] = true;
//	}
//	for(int i = 1; i <= n; i++){
//		if(!v[i])s+=a[i][2];
//	}
//	return s;
//}
long long aa(long long n){
	vector<int> x;
	long long s = 0;
	for(long long i = 1; i <= n; i++){
		x.push_back(a[i][1]);
	}
	sort(x.begin(),x.end(),cmpp);
	for(long long i = 0; i < n/2; i++){
		s+=x[i];
	}
	return s;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		bool B = true;
		bool A = true;
		for(long long i = 1; i <= n; i++){
			for(long long j = 1; j <= 3; j++){
				cin >> a[i][j];
				if(j==3 && B){
					if((a[i][2] != 0) ||(a[i][3] != 0))A=false;
					if(a[i][3] != 0)B=false;
				}
			}
		}
		if(A){

			ans=aa(n);
		}else if(n == 2){
			for(long long i = 1; i <= 3; i++){
				for(long long j = i+1; j <= 3; j++){
					ans = max(a[1][i]+a[2][j],ans);
					//cout << a[1][i] << " " << a[2][j] << endl;
				}
			}
			for(long long j = 1; j <= 3; j++){
				for(long long i = j+1; i <= 3; i++){
					ans = max(a[1][i]+a[2][j],ans);
					//cout << a[1][i] << " " << a[2][j] << endl;
				}
			}
		}else if(n == 4){
			for(long long i = 1; i <= 3; i++){
				for(long long j = 1; j <= 3; j++){
					for(long long k = 1; k <= 3; k++){
						for(long long l = 1; l <= 3; l++){
							if(!((i==j&&j==k)||(i==j&&j==l)||(j==k&&k==l)||(i==k&&k==l))){
									ans = max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
								if(ans == a[1][i]+a[2][j]+a[3][k]+a[4][l]){
									//cout << a[1][i] << " " << a[2][j] << " " << a[3][k] << " " << a[4][l] << endl; 
								}	
							}
							
						}
					}
				}
			}
		}else{
			long long s = 0;
			int club[4] = {0,0,0,0};
			for(long long i = n; i >= 1; i--){
				long long mx = 0;
				for(long long j = 3; j >= 1; j--){
					mx = max(a[i][j],mx);	
				}

				s+=mx;
			}
			ans = s;
		}
		cout << ans << endl;
	}
	return 0;
}
