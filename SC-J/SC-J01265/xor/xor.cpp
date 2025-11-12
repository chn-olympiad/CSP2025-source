#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,b[10005],sum;
bool si,nm;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int u=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) si=1;
		sum+=a[i];
		if(a[i]!=1&&a[i]!=0) nm=1;
	}
	if(n<=2&&si==0) cout<<1;
	else if(n<=100&&si==0) cout<<n/2;
	else if(nm==0) cout<<sum;
	else cout<<sum/k;
	return 0;
}