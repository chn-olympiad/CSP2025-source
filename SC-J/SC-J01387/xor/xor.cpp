#include<bits/stdc++.h>
using namespace std;

long long n,k,a[500005],ans;




int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			int res=a[i];
			for(int z=i+1;z<=j;++z){
				res^=a[z];
			}
			if(res==k){
				ans++;
				i=j+1;
			}
		}
	}
	cout<<ans;
	return 0;
}