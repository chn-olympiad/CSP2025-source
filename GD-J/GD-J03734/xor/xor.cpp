#include<bits/stdc++.h>
using namespace std;
namespace my_space{
	using ll = long long;
	constexpr int maxn = (1<<20)+50,N = 5e5+50;
	int a[maxn],qz[N],qzmx[N];
	int main(){
		freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		int n,k;
		cin>>n>>k;
		memset(a,-1,sizeof a);
		a[0] = 0;
		for(int i=1;i<=n;i++){
			cin>>qz[i];
			qz[i]^=qz[i-1];
			int temp = qz[i]^k;
			qzmx[i] = qzmx[i-1];
			if(a[temp]!=-1) {
				int ne = qzmx[a[temp]]+1;
				qzmx[i] = max(qzmx[i],ne);
			}
			a[qz[i]] = i;
		}
		cout<<qzmx[n]<<'\n';
		return 0;
	}
}
int main(){
	return my_space::main();
}


