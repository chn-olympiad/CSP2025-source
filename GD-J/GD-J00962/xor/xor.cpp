#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500100];
int ans=0,ans2=0;
int now;
int visr;
int visl;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	visr=0;
	visl=n+5;
	for(int i=1;i<=n;i++){
		now=0;
		for(int j=i;j<=n;j++){
			now=(now^a[j]);
			if(now==k && visr<i){
				visr=j;
				ans++;
				break;
			}
		} 
	}
	for(int i=n;i>=1;i--){
		now=0;
		for(int j=i;j<=n;j++){
			now=(now^a[j]);
			if(now==k && visl>j){
				visl=i;
				ans2++;
				break;
			}
		} 
	}
	cout<<max(ans,ans2);
	return 0;
	
}
