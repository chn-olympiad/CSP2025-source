//xor
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,k,a[N],n0,n1,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) n0++;
		if(a[i]==1) n1++;
	}
	if(k==1){
		ans=n1;
	}
	if(k==0){
		if(n1==n) ans=n1/2;
		else{
			ans=n0;
		}
	}
	cout<<ans; 
	
	return 0;
}
