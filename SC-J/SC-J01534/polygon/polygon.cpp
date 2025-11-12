#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+5,mod=998244353;
int n,a[N];
ll ans,cnt,bjt[5005][3];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=(ans+cnt)%mod,cnt=(cnt*2)%mod;
		for(int j=5000;j;j--){
			if(j>a[i])ans=(ans+bjt[j][2])%mod;
			if(j+a[i]<=5000)
				bjt[j+a[i]][2]=(bjt[j+a[i]][2]+bjt[j][2]+bjt[j][1])%mod;
			else cnt=(cnt+bjt[j][2]+bjt[j][1])%mod;
		}
		bjt[a[i]][1]++;
	}
	cout<<ans;
	return 0;
}