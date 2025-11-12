#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int pre[N],a[N];
int n,k,tot=0,ans=0;
bool vis;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) ans++;
		pre[i]=pre[i-1]^a[i];
	}
	int i=1;
	while(i<=n){
		vis=0;
		int x;
		for(int j=i;j<=n;j++){
			if(pre[j]==k){
				tot++;
				vis=1;
				x=j;
				break;
			}
		}
		if(!vis) i++;
		else i=x+1;
		pre[i-1]=0;
		for(int l=i;l<=n;l++){
			pre[l]=pre[l-1]^a[l];
		}
	}
	cout<<max(ans,tot);
	return 0;
}
