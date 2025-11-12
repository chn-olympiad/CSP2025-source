#include <iostream>
using namespace std;
const int N=5e5+5,K=(1<<20)+114514;
int a[N],f[N],tx[K];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k;cin >> n >> k;
	for (int i=1;i<=n;++i) cin >> a[i],a[i]^=a[i-1];
	for (int i=0;i<K;++i) tx[i]=-114514;
	tx[0]=0;
	for (int i=1;i<=n;++i){
		if (tx[a[i]^k]!=-114514){
			f[i]=f[tx[a[i]^k]]+1;
		}
		f[i]=max(f[i],f[i-1]);
		tx[a[i]]=i;
	}
	cout<<f[n]<<"\n";
	cout.flush();
	return 0;
}
/*
长恨这无限黄昏无限哀
显然有贪心，对于每个点，选择越靠后越好
*/