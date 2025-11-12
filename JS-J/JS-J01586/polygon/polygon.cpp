#include <fstream>
#define maxn 5005
std::ifstream fin("polygon.in");
std::ofstream fout("polygon.out");
const int mod=998244353;
int n;
int a[maxn];
inline long long solve(int i,long long total,int maxx){
	if(i==n+1){
		if(total>2*maxx){
			return 1;
		}
		return 0;
	}
	return (solve(i+1,total+a[i],std::max(maxx,a[i]))+solve(i+1,total,maxx))%mod;
}
int main() {
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	fout<<solve(1,0,a[1]);
}
