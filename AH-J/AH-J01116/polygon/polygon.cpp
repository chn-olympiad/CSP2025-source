#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int s[5005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i];
		s[i]+=s[i-1];
	}
	if(n==3){
		if(s[3]>a[3]*2){
			cout<<1;
		}
		else
			cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
