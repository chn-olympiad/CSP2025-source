#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll nmax=998244353;
ll n,a[10000],s[10000],h,cnt;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	if(n==3){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					h=a[i]+a[j]+a[k];
					if(h>a[j]*2) cnt++;
					if(cnt>=nmax) cnt-=nmax;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}