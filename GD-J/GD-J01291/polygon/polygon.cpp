#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve();
const int MAXN=500005;
int a[MAXN],b[MAXN];
int ans=0,ma=0,n;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	if(n==3){
		if(a[3]<a[1]+a[2]){
			cout<<1;
			return ;
		}
	}
	else{
		if(a[3]<a[1]+a[2]){
			ans++;
		}
		if(a[4]<a[1]+a[2]+a[3]){
			ans++;
		}
		
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		for(int i=1;i<=n;i++){
			b[i]+=b[i-1];
		}
		for(int w=4;w<=n;w++){//几边型 
			for(int i=5;i<=n;i++){//max 
				for(int j=4;j<n;j++){//第二 
					for(int k=1;k<n-1;k++){//删去 
						if(b[j]-b[k]+b[k-(j-w+1)]>b[i]){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans;
	}
	return ;
}

