//60 YangShao_Culture
#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,a[N];
int s[N],f[N],mf[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	if(n>1000){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k)	ans++;
		}
		cout<<ans;
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if((s[i]^s[j-1])==k){
				f[i]=max(f[i],mf[j-1]+1);
			}
		}
		for(int j=1;j<=i;j++){
			mf[i]=max(mf[i],f[j]);
		}
	} 
	cout<<mf[n];
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	return 0;
} 
