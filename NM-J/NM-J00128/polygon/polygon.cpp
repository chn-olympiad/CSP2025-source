#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool fun(int a,int b){
	return a>b;
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	long long n = 0;
	vector<long long> vec1;
	scanf("%lld",&n);
	for(long long i = 0;i<n;i++){
		long long t = 0;
		scanf("%lld",&t);
		vec1.push_back(t);
	}
	int x = 2;
	long long id = 0;
	vector<long long> vec3;
	for(long long i = n-1;i>=0;i--){
		for(long long j = i-x;j>=0;j--){
			vector<long long> vec2;
			vec2.push_back(vec1[i]);
			for(long long k = j;k<i;k++){
				vec2.push_back(vec1[k]);
			}
			sort(vec2.begin(),vec2.end(),fun);
			long long a = 0;
			for(long long k = 1;k<vec2.size();k++){
				a+=vec2[k];
			}
			if(a>vec2[0]){
				id++;
				long long y = 0;
				for(long long k = 0;k<vec2.size();k++){
					y=y*10+vec2[k];
				}
				for(long long k = 0;k<vec3.size();k++){
					if(y==vec3[k]){
						id--;
						break;
					}else{
						vec3.push_back(y);
					}
				}
			}
		}
		x++;
		for(long long j = i-1;j>=0;j--){
			vector<long long> vec2;
			vec2.push_back(vec1[i]);
			vec2.push_back(vec1[j]);
			for(long long k = j-1;k>=0;k--){
				vec2.push_back(vec1[k]);
				sort(vec2.begin(),vec2.end(),fun);
				long long a = 0;
				for(long long k = 1;k<vec2.size();k++){
					a+=vec2[k];
				}
				if(a>vec2[0]){
					id++;
					long long y = 0;
					for(long long k = 0;k<vec2.size();k++){
						y=y*10+vec2[k];
					}
					for(long long k = 0;k<vec3.size();k++){
						if(y==vec3[k]){
							id--;
							break;
						}else{
							vec3.push_back(y);
						}
					}
				}
			}
		}
	}
	if(id>0){
		id--; 
	}
	printf("%lld",id%998244353);
	
	return 0;
}
