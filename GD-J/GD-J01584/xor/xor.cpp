#include<bits/stdc++.h>
#define psb push_back
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int N=5e5+5,M=1<<20;
int n,k,a[N],lst[M],mi[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=0;i<M;i++)lst[i]=n+1;
	mi[n+1]=n+1;
	for(int i=n;i>=1;i--){
		lst[a[i]]=i;
		mi[i]=min(mi[i+1],lst[a[i-1]^k]);
	}
	int ans=0,p=mi[1];
	while(p<=n)ans++,p=mi[p+1];
	cout<<ans<<endl;
	return 0;
}/*

*/
