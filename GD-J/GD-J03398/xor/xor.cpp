#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],q[500005],sum;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=(a[i]^q[i-1]);
	}
	int last=1;
	for(int i=1;i<=n;i++){
		for(int j=last;j<=i;j++) if((q[i]^q[j-1])==k){
			sum++;
			last=i+1;
			break;
		}
	}
	cout<<sum;
	return 0;
}
