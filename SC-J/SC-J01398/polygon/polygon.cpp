#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=998244353;
ll a[500010],n,ans;
bool b[500010];
bool ifs(int l,int r,int i){
	ll sum=0,maxz=INT_MIN,xpf=i;
	for(ll kcsp=l;kcsp<=r;kcsp++){
		if(b[kcsp]==1){
			sum+=a[kcsp];
			maxz=max(maxz,a[kcsp]);
			xpf--;
		}	
	}
	if(maxz*2<sum&&xpf>0){
		return 1;
	}
	else return 0;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=3;i<=n-1;i++){
		for(int j=1;j<=i-1;j++){
			for(int k=j+1;k<=i;k++){
				b[k]=1;
				if(ifs(1,n,i))ans++;
				b[k]=0;
				if(ifs(1,n,i))ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
