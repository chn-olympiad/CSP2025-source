#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int MAXN=5e+5;
ll n,a[MAXN],ans,maxx,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
			sum+=a[i];
		}
		if(sum>maxx*2) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum=a[i],maxx=a[i];
		for(int j=i+1;j<=n;j++){
			if(i==j) continue; 
			maxx=max(maxx,a[j]);
			sum+=a[j];
			if(sum>maxx*2){
				ans++;
				break;
			}
		} 
	} 
	cout<<ans+1; 
	return 0;
} 
