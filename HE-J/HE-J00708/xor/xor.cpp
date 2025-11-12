#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10;
int n,k,x[N],a[N],ans,l=1,t;

signed main(){
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) x[i]=x[i-1]^a[i];
	for(int i=1;i<=n;i++)
		for(int j=l;j<=i;j++)
			if((x[i]^x[j-1])==k){
				++ans;
				l=i+1;
				break;
			}
	cout<<ans;
	return 0;
}
