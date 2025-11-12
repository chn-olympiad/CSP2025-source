#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5,mod=998244353;
int n,a[N],C[N][N],ans;

void pre(){
	for(int i=1;i<=n;i++) C[1][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			if(C[i][j]>=mod) C[i][j]-=mod;
		}
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=20){
		ll ans=0;
		for(int i=7;i<(1<<n);i++){
			int mx=0,cnt=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					cnt+=a[j+1];
					mx=max(mx,a[j+1]);
				}
			}
			if(cnt>mx*2) ans++;
		}
		cout<<ans<<"\n";
	} else if(a[n]==1){
		pre();
		for(int i=3;i<=n;i++){
			for(int j=3;j<=n;j++){
				ans+=C[j-1][i-1];
				if(ans>=mod) ans-=mod;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
