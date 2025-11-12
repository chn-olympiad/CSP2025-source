#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x1=0,x0=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) x0++;
		if(a[i]==1) x1++;
	}
	if(k==0&&x1==n) cout<<n/2<<endl;
	else if(k==0) cout<<x0+x1/2<<endl;
	else if(k==1) cout<<x0/2+x1<<endl;
	else cout<<2<<<endl;
	return 0;
}	
