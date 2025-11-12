#include<bits/stdc++.h>
using namespace std;

int n,k,a,ans,x,f[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		f[i]=f[i-1]^a;
	}
	for(int i=1;i<=n;i++){
		for(int j=x;j<i;j++){
			if((f[i]^f[j])==k){
				ans++;
				x=i;
				break;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
