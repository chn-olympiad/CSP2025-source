#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int p=998244353 ;
int n,a[N],f[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < (1<<n); i++){
		for(int j = 1; j <= n; j++){
			f[j]=0;
		}
		int t=i,sm=0,mx=-1,cnt=0;
		for(int j = 1; j <= n; j++){
			if(t&1){
				f[j]=1;cnt++;
			}
			t>>=1;
		}
		if(cnt<3)continue;
		for(int j = 1; j <= n; j++){
			if(f[j]){
				sm+=a[j];mx=max(mx,a[j]);
			}
		}
		if(sm>mx*2)ans++;
		ans%=p;
	}
	cout << ans;
	return 0;
}


