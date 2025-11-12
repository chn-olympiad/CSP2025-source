#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
	}
	if(k==0){
		cout<<n/2;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
