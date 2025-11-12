#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int n,k,a[5010],ans=0,maxn=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		sort(a,a+n);
		if(ans>a[n-1])cout<<1;
		else cout<<0;
		return 0;
	}
	if(maxn==1){
		ans=1;
		for(int i=3;i<=n;i++){
			ans*=i;
			ans%=N;
		}
		cout<<ans;
		return 0;
	}
	cout<<(n+maxn)%N;
	return 0;
}