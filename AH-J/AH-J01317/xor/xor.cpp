#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7;
int n,k,a[N],ans;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int l=1;l<=n;l++){
		int op=a[l];
		if(op==k){
			ans++;
			continue;
		}
		for(int r=l+1;r<=n;r++){
			op^=a[r];
			if(op==k){
				ans++;
				l=r;
				break;
			}
		}
	}
    cout<<ans<<"\n";
    return 0;
}
