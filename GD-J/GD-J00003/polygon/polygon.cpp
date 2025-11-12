#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=0;j<(1<<i-1);j++){
			int s=0;
			for(int k=1;k<i;k++){
				if(1<<(k-1)&j){
					s+=a[k];
				}
			}
			if(s>a[i])ans=(ans+1)%998244353;
		}
	}
	cout<<ans;
	return 0;
}
