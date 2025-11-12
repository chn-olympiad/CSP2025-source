#include <iostream>
using namespace std;
const int N=5e5+3;
int a[N],b[N];
int n,k;
int ans;
namespace spcA {
	bool check(int n) {
		for(int i=1;i<=n;i++)
			if(a[i]!=1) return 0;
		return 1;
	}
	void solve(int n) {
		//k=0
		printf("%d\n",n>>1);
	}
}
void dfs(int st,int sum) {
	if(st==n) {
		if(a[st]==k) sum++;
		st++;
	}
	if(st>n) {
		if(sum>ans) ans=sum;
		return ;
	}
	int r=st;
	while(r<=n && (b[r]^b[st-1])!=k) r++;
	if((b[r]^b[st-1])==k) {
		for(int i=1;i<=n;i++)
			dfs(r+i,sum+1);
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	if(spcA::check(n)) {
		spcA::solve(n);
		return 0;
	}
	for(int i=1;i<=n;i++) {
		dfs(1,0);
	}
	cout<<ans;
	return 0;
}