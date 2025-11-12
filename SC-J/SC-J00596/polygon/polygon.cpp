#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '/n'
int a[5005],b[5005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int m=998244353;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		b[i]+=a[i];
	}
	sort(a+1,a+1+n);
	int cnt=0;
	if(n<=3){
		if(b[n]<a[n]*2){
			cout<<1;
			return 0;
		}
	}
	for(int i=1; i<=n; i++){
		if(a[i]==1){
			cnt++;
		}
	}
	if(cnt==n){
		cout<<0;
		return 0;
	}
	return 0;
}