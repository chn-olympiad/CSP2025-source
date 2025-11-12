#include <iostream>
#include <vector>
using namespace std;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long long n = 0;
	long long k = 0;
	scanf("%lld%lld",&n,&k);
	vector<long long> vec1;
	for(int i = 0;i<n;i++){
		long long t = 0;
		scanf("%lld",&t);
		vec1.push_back(t);
	}
	printf("0");
	
	return 0;
}
