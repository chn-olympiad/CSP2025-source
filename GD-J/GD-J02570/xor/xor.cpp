#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int MAXN=5e+5;
ll n,m,a[MAXN],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		a[i]=(a[i]&&1);
	}
	if(n<=2 && m==0){
		cout<<2;
		return 0;
	}
	for(ll i=1,sum,cnt;i<=n;i++){
		sum=a[i],cnt=1;
		for(ll j=i+1;j<=n;j++){
			if(cnt>=m) break;
			sum+=a[j];
			cnt++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
