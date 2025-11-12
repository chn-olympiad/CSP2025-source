#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int cnt[N],x[N],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%d",&x[i]);
		++cnt[x[i]];
	}
	if(cnt[1]==n){
		int ans=1;
		while(cnt[1]--){
			ans*=2;
			ans%=998244353;
		}
		cout<<ans-n*(n-1)/2;
	}
	else if(n==3){
		if(x[1]+x[2]+x[3]>2*max(max(x[1],x[2]),x[3]))cout<<1;
		else cout<<0;
	}
	return 0;
}
