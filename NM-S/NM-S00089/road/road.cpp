#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dfs(int vec1[1005][1005],long long n,long long index,long long shu){
	bool walk[1005]= {};
	walk[index] = true;
	for(long long i = index;i<=n;i++){
		if(walk[i] == false && vec1[index][i] == 1){
			if(vec1[index][i]==shu){
				return shu;
			}
			walk[index] = true;
			dfs(vec1,n,i,shu);
		}
	}
	return 0;
}
int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	long long n = 0;
	long long m = 0;
	long long k = 0;
	scanf("%lld%lld%lld",&n,&m,&k);
	int vec1[1005][1005] = {};
	long long zong = 0;
	for(int i = 1;i<=m;i++){
		long long left = 0;
		long long right = 0;
		long long qian = 0;
		scanf("%lld%lld%lld",&left,&right,&qian);
		if(dfs(vec1,n,left,right) == right){
			continue;
		}else{
			vec1[left][right] = 1;
			vec1[right][left] = 1;
			zong+=qian;
		}
	}
	for(int i = 0;i<k;i++){
		long long shu;
		long long prize;
		long long q1;
		long long q2;
		long long q3;
		scanf("%lld%lld%lld%lld%lld",&shu,&prize,&q1,&q2,&q3);
	}
	printf("%lld",zong);

	return 0;
}
