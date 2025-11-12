#include<bits/stdc++.h>
using namespace std;
#define int long long
#define psb push_back
const int N=2e6+10;
int n,k,ans,a[N],lst[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i],a[i]^=a[i-1];
	memset(lst,-1,sizeof lst);
	lst[0]=1;
	for(int i=1,j=0;i<=n;++i){
		if(lst[a[i]^k]>j) ++ans,j=i;
		lst[a[i]]=i+1;
	}
	cout<<ans;
	return 0;
}
