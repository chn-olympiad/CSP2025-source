#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500010],s[500010],ans=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int l=0,r=1;
	while(r<=n){
		if(a[r]==k){
			ans++;
			l=r;
		}else{
			for(int j=l;j<r;++j){
				if((a[j]^a[r])==k){
					ans++;
					l=r;
					break;
				}
			}
		}
		r++;
	}
	cout<<ans<<endl;
	return 0;
}
