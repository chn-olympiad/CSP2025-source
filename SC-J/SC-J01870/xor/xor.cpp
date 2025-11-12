#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int n,k,l=1,r=1,a[N],sum[N],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum[i]=a[i];
	}
	for(int i=2;i<=n;++i){
		sum[i]=sum[i-1]^a[i];
	}
	while(1){
		if(r>n&&l>n){
			break;
		}
		else if(r==n&&l<=n){
			if((sum[r]^sum[l-1])==k){
				ans++;
				break;
			}else{
				l++;
			}
		}else{
			if(l==r){
				if(a[l]==k) {
					ans++;
					l++;
					r++;
				}else{
					r++;
				}
			}else{
				if((sum[r]^sum[l-1])==k){
					ans++;
					r++;
					l=r;
				}else{
					r++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}