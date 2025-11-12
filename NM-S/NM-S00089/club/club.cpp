#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct xinsheng{
	long long a1;
	long long a2;
	long long a3;
};
bool fun(long long a,long long b){
	return a>b;
}
int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	long long n = 0;
	scanf("%lld",&n);
	for(long long i = 0;i<n;i++){
		long long m = 0;
		scanf("%lld",&m);
		vector<xinsheng> vec1;
		for(long long j = 0;j<m;j++){
			xinsheng xs = {};
			scanf("%lld%lld%lld",&xs.a1,&xs.a2,&xs.a3);
			vec1.push_back(xs);
		}
		long long a[8] = {};
		long long manyizhi = 0;
		for(long long j = 0;j<vec1.size();j++){
			if(vec1[j].a1 > vec1[j].a2 && vec1[j].a1>vec1[j].a3){
				if(a[1]==m/2){
					if(vec1[j].a2>vec1[j].a3 && a[2] != m/2){
						a[2]++;
						manyizhi+=vec1[j].a2;
					}else {
						a[3]++;
						manyizhi+=vec1[j].a3;
					}
					continue;
				}
				a[1]++;
				manyizhi+=vec1[j].a1;
			}else if(vec1[j].a2 > vec1[j].a1 && vec1[j].a2>vec1[j].a3){
				if(a[2]==m/2){
					if(vec1[j].a1>vec1[j].a3 && a[1] != m/2){
						a[1]++;
						manyizhi+=vec1[j].a1;
					}else {
						a[3]++;
						manyizhi+=vec1[j].a3;
					}
					continue;
				}
				a[2]++;
				manyizhi+=vec1[j].a2;
			}else if(vec1[j].a3 > vec1[j].a2 && vec1[j].a3>vec1[j].a1){
				if(a[3]==m/2){
					if(vec1[j].a1>vec1[j].a2 && a[1] != m/2){
						a[1]++;
						manyizhi+=vec1[j].a1;
					}else {
						a[2]++;
						manyizhi+=vec1[j].a2;
					}
					continue;
				}
				a[3]++;
				manyizhi+=vec1[j].a3;
			}
		}
		if(m==2){
			vector<long long> vec2(100);
			vec2[0] = manyizhi;
			vec2[1] = vec1[0].a2+vec1[1].a1;
			vec2[2] = vec1[0].a2+vec1[1].a3;
			vec2[3] = vec1[0].a3+vec1[1].a1;
			vec2[4] = vec1[0].a2+vec1[1].a3;
			sort(vec2.begin(),vec2.end(),fun);
			printf("%lld",vec2[0]);
			continue;
		}
		printf("%lld",manyizhi);
	}

	return 0;
}
