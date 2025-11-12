#include<bits/stdc++.h>
#define ll long long;
using namespace std;
int n,k,a[500005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0) cout<<n/2;
	return 0;
}


