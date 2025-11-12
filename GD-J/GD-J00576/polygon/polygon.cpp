#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
ll dele=998244353;
ll a[N],b[N];
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ll ans=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=2;j<i;j++){
			if(a[i]<b[j]) ans++;
		}
		ans%=dele;
	}
	cout<<ans;
	return 0;
}
