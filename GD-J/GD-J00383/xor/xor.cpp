#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,x[1000005],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		x[i]^=x[i-1];
	}
	int l=0,r=0,lt=1;
	for(int i=1;i<=n;i++){
		l=lt,r=i;
		for(int j=l;j<=r;j++){
			if((x[r]^x[j-1])==k){
				lt=r+1,ans++;
				break;
			}
		}
	}
	cout<<ans;
} 
