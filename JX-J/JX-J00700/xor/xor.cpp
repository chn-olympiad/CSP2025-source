#include <bits/stdc++.h>
using namespace std;
int n,k,a[500003],b[500003],tmp,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=i;j<=n;j++){
			tmp^=a[j];
			if(tmp==k){
				b[i]++,b[j+1]--,ans++;
				break;
			}
		}
	}
	for(int i=1;i<=n+1;i++){
		tmp+=b[i];
		if(tmp>=2&&b[i]) ans--;
	}
	cout<<ans<<'\n';
	return 0;
}
