#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=5e5+10;
ll n,k,ans=0;
ll a[INF],w[INF];
ll read(){
	ll p=0,k=1;
	char c=getchar();
	while (c<'0'||c>'9'){
		if(c=='-')k=-k;
		c=getchar();
	}
	while (c>='0'&&c<='9') p=p*10+(c-'0'),c=getchar();
	return p*k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
		w[i]=w[i-1]^a[i];
	}
	ll END=1;
	//双指针复杂度On^2 期望60分 
	for (int i=1;i<=n;i++){
		for (int j=i;j>=END;j--) {
			if(int(w[i]^w[j-1])==k) {
				ans++,END=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
