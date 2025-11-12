#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
struct Seg{
	int l,r;
	Seg(){}
	Seg(int a,int b):l(a),r(b){}
	inline bool operator <(const Seg &a)const{
		return (r!=a.r?r<a.r:l<a.l);
	}
};
vector<Seg> v;
int n,k,a[500005],sum[500005],dp[500005],p;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((sum[r]^sum[l-1])==k){
				v.emplace_back(Seg(l,r));
				break;
			}
		}
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		while(v[p].r==i){
			dp[i]=max(dp[i],dp[v[p].l-1]+1);
			p++;
		}
	}
	cout<<dp[n]<<endl;
}
