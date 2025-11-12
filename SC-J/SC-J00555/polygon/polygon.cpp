#include<bits/stdc++.h>
using namespace std;
int L[500005],n;
using ll=long long;
ll f(int i,ll total,int start){
	ll ans=0;
	for(int j=start;j<i;j++){
		if(total-L[j]>L[i]){
			ans+=1+f(i,total-L[j],j+1);
		}
		else{
			return ans;
		}
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll total=0;cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>L[i];
	}
	sort(L+1,L+1+n);
	for(int i=1;i<=n;i++){
		if(i>=3&&total>L[i]){
			ans+=1+f(i,total,1);
			ans%=998244353;
		}
		total+=L[i];
	}
	cout<<ans;
	return 0;
}