#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n;
int a[10010];
bool cmp(int x,int y){
	return x<=y;
}
ll jc(int x){
	ll cnt=1;
	for(int i=2;i<=x;i++){
		cnt*=i;
		cnt%=mod;
	}
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			flag=false;
			break;
		}
	}
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	if(n==3){
		sort(a+1,a+n+1,cmp);
		ll tmp=0;
		for(int i=1;i<n;i++){
			tmp+=a[i];
		}
		if(tmp<=a[n]){
			cout<<0<<endl;
		}else cout<<1<<endl;
	}else if(n>3&&flag){
		ll ans=0;
		for(int i=3;i<=n;i++){
			ll now=1;
			if(i<n-i){
				
				for(int j=n-i+1;j<=n;j++){
					now*=j;
					now%=mod;
				}
				now/=jc(i);
			}else{
				for(int j=i+1;j<=n;j++){
					now*=j;
					now%=mod;
				}
				now/=jc(n-i);
			}
			ans+=now;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
