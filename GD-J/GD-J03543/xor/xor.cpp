#include<bits/stdc++.h>
#define int long long
using namespace std;
void init(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}
int n,k,ans,zero,one;
int a[500001],sum[500001];
bool bj[500001];
signed main(){
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	init();
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zero+=(a[i]==0);
		one+=(a[i]==1);
		if(a[i]==k){
			ans++;
			bj[i]=1;
		}
	}
	if(zero==one && k>=0 && k<=1){
		if(k==0){
			cout<<zero;
		}
		else{
			cout<<one;
		}
		return 0;
	}
	sum[1]=a[1];
	for(int i=1;i<=n;i++){
		sum[i]=(sum[i-1] ^ a[i]);
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j+i<=n;j++){
			int he=sum[i+j-1] ^ sum[j-1];
			bool p=0;
			if(he!=k){
				continue;
			}
			for(int k=j;k<=i+j-1;k++){
				if(bj[k]){
					p=1;
					break;
				}
			}
			if(p){
				continue;
			}
			for(int k=j;k<=i+j-1;k++){
				bj[k]=1;
			}
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
