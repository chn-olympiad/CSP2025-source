#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int maxn=-1;
int sum;
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
		sum+=a[i];
	}
	int mann=2*maxn;
	if(sum<=mann){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(sum>mann) ans++;
		cout<<ans;
		return 0;
	}
	if(maxn==1){
		ans=n*(n-1)*(n-2)/6%998244353;
		cout<<ans;
		return 0;
	}
	return 0;
}
