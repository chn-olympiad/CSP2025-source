#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5010];
long long ans=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1||n==2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) ans=(ans*2)%N;
	cout<<(ans+N-1-n-n*(n-1)/2)%N;
	return 0;
}

