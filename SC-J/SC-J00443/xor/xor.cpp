#include<bits/stdc++.h>
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
using namespace std;
int n,k;
int a[500010];
int maxx=0;
int minx=INT_MAX;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	I AK CSP 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		minx=min(minx,a[i]);
	}
	if(k==0 && maxx==1 && minx==1){
		if(n%2==0) cout<<n/2;
		else cout<<(n-1)/2;
	}else if(k<=1 && maxx==1 && minx==0){
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0 || (a[i]==1 && a[i-1]==1)){
					ans++;
				}
			}
			cout<<ans;
		}else if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
		}
	}
	return 0;
}