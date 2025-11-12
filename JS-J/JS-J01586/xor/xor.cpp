#include <fstream>
#include <set>
#define maxn 500005
std::ifstream fin("xor.in");
std::ofstream fout("xor.out");
int n,k;
int a[maxn];
int cnt=0;
int xor_num(int l,int r){
	int sum=a[l];
	for(int i=l+1;i<=r;i++){
		sum=sum xor a[i];
	}
	return sum;
}
void solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(xor_num(j,i)==k){
				ans++;
			}
		}
	}
	fout<<ans<<std::endl;
}
int main() {
	fin>>n>>k;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	solve();
}