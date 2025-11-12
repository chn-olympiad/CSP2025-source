#include<iostream>
using namespace std;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	/*string s;cin>>s;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
	}*/
	long long sum=1;
	int jian=0;
	for(int i=n;jian<m;i--){
		jian++;
		sum*=m;
		sum%=mod;
	}
	cout<<sum;

	return 0;
}
//Z-9
//Zhao
