#include <bits/stdc++.h> 
using namespace std;
#define ll long long

const ll N=1e5+5;

ll n,ans=0,sum=0;
ll a[N][3],cnt[3],S[N];

void dfs(ll k) {
	if(k==n+1) ans=max(ans,sum);
	else {
		if(sum+S[n]-S[k-1]<ans) return ;
		for(ll i=0;i<=2;++i)
			if(cnt[i]<n/2) {
				sum+=a[k][i];
				++cnt[i];
				dfs(k+1);
				sum-=a[k][i];
				--cnt[i];
			}	
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	ll T;
	std::cin>>T;
	while(T--) {
		cnt[0]=cnt[1]=cnt[2]=0;
		S[0]=0;
		std::cin>>n;
		ans=sum=0;
		for(ll i=1;i<=n;++i) 
			std::cin>>a[i][0]>>a[i][1]>>a[i][2],
			S[i]=S[i-1]+max(a[i][0],max(a[i][1],a[i][2]));
		dfs(1);
		std::cout<<ans<<'\n';
	}
	
	return 0;
}