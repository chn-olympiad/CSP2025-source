#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else{
		cout<<(((((cnt%mod)*((cnt-1)%mod))%mod)*((cnt-2)%mod))%mod)/6;
	}
	return 0;
}
