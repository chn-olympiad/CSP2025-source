#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5010,MOD=998244353;
int n;
int a[MAXN];
ll ji[MAXN];
ll ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ji[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int cnt=a[i]+a[i+1];
		ll tmp=1;
		ll NUM=ji[a[i]]%MOD;
		tmp=tmp*NUM%MOD;
		if(a[i]==a[i+1]){
			NUM--;
			tmp=tmp*NUM%MOD;
		}
		for(int j=i+2;j<=n;j++){
			cnt+=a[j];
			if(a[j]==a[j-1]){
				tmp=tmp*NUM%MOD;
				NUM--;
			}else{
				NUM=ji[a[j]]%MOD;
				if(tmp!=1){
					tmp/=2;
				}
				tmp=tmp*NUM%MOD;
			}
			if(cnt>(a[j]*2)){
				ans=(ans+tmp)%MOD;
			}
		}
	}
	cout<<ans;
	return 0;
}
