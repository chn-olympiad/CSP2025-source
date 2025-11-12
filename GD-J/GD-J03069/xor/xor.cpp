#include<bits/stdc++.h>
#define int unsigned int
using namespace std;

int n,k;
int a[500005],x[500005],ans[500005];

signed main(){
	ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) x[i]=(x[i-1]^a[i]);
	int num=0;
	if(1ll*n*(n+1)/2<2e8){
		for(int i=1;i<=n;i++){
			ans[i]=ans[i-1];
			for(int j=1;j<=i;j++) if((x[i]^x[j-1])==k) ans[i]=max(ans[i],ans[j-1]+1);
		}
		cout<<ans[n];
	}
	else{
		int p=0;
		for(int i=1;i<=n;i++){
			num^=a[i];
			if(num==k){
				num=0;
				p++;
			}
		}
		cout<<p;
	} 
}
