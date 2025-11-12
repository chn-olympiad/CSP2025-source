#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[5145145],f[5145145],cnt,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
		for(int j=cnt;j<i;j++){
			if((f[i]^f[j])==m){
				ans++;
				cnt=i;
				break;
			}
		}
	}
	cout<<ans;
}
