#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=998244353;
int n,a[5005],maxn,sum,q;
ll ans=0;
bool b=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) b=false;
	}
	if(b){
		ans=2;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=N;
		}
		ans-=(n*(n-1)+n+1);
		ans+=N;
		ans%=N;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n<=20){
		for(int i=1;i<(1<<n);i++){
			int k=i;
			int t=n;
			q=0;
			maxn=0;
			sum=0;
			while(k){
				if(k%2) {
					maxn=max(maxn,a[t]);
					q+=a[t];
					sum++;
				}
				k/=2;
				t--;
			}
			if(maxn*2<q&&sum>=3) ans++;
		}
	}
	cout<<ans;
	return 0;
}
