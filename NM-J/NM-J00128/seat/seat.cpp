#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool fun(int a,int b){
	return a>b;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	long long n = 0;
	long long m = 0;
	scanf("%lld%lld",&n,&m);
	long long a[15][15] = {};
	vector<long long> vec1;
	for(long long i = 0;i<n*m;i++){
		long long t = 0;
		scanf("%lld",&t);
		vec1.push_back(t);
	}
	long long x = vec1[0];
	sort(vec1.begin(),vec1.end(),fun);
	long long id = 0;
	for(long long i = 1;i<=m;i++){
		if(i%2!=0){
			for(long long j = 1;j<=n;j++){
				a[j][i] = vec1[id];
				id++;
			}
		}else{
			for(long long j = n;j>0;j--){
				a[j][i] = vec1[id];
				id++;
			}
		}
	}
	for(long long i = 1;i<=n;i++){
		for(long long j = 1;j<=m;j++){
			if(a[i][j] == x){
				printf("%lld %lld",j,i);
			}
		}
	}
	
	return 0;
}
