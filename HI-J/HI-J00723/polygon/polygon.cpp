#include <bits/stdc++.h>
#define ll unsigned long long
#define ul unsigned int
using namespace std;
int n;
int a[5000000];
ul vit[5000000],cnt=1;
bool vis[9000000];
ll ans;
bool check(int ky){
	for(int i=1;i<=cnt;i++){
		if(vit[i]==ky){
			return 0;
		}
	}
	vit[cnt]=ky;
	cnt++;
	return 1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll s=0;
	int ma=-0x7fffffff;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		ma=max(ma,a[i]);
	}
	if(s>2*ma){
		ans=1;
	}
	for(int b=4;b<=n;b++){
		for(int l=1;l<=n-b+1;l++){
			int r=l+b-1;
			for(int i=l;i<=r;i++){
				int mx=-0x7fffffff;
				ll keyh=0;
				ll sum=0;
				for(int j=l;j<=r;j++){
					if(j==i){
						continue;
					}
					keyh*=10;
					keyh+=j;
					sum+=a[j];
					mx=max(mx,a[j]);
				}
				if(n<=6){
					if(sum>2*mx&&vis[keyh]==0){
						//cout<<keyh<<"  "<<endl;
						vis[keyh]=1;
						ans++;
						ans=ans%998244353;
					}
				}else{
					if(sum>2*mx&&check(keyh)==1){
						//cout<<keyh<<"  "<<endl;
						ans++;
						ans=ans%998244353;
					}	
				}
			}
		}
	}
	cout<<ans;
	return 0;
}//998244353
