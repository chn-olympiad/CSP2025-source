#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int N=5e5+5,M=1e6+5e4,mod=1e9+7;
int n,k,a[N],y[N],v[N],ans,t1,t0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) t1++;
		if(a[i]==0) t0++;
	}
	if(t1==n){
		if(k==1) cout<<n;
		if(k==0) cout<<n/2;
		if(k>1) cout<<0;
		return 0;
	}
	if(t1+t0==n){
		if(k==1) cout<<t1;
		else if(k>1) cout<<0;
		else{
			int cnt=t0,f;
			for(int i=1;i<=n;i++){
				if(a[i]==0) f=0;
				else if(f==0) f=1;
				else{
					cnt++;
					f=0;
				}
			}
			cout<<cnt;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		y[i]=y[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((y[j]^y[j-i])==k){
				int f=1;
				for(int m=j-i+1;m<=j;m++){
					if(v[m]==1){
						f=0;
						break;
					}
				}
				if(f){
					ans++;
					for(int m=j-i+1;m<=j;m++){
						v[m]=1;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 