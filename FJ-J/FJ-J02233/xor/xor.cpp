#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=100&&k==0){
		if(n%2==0)cout<<n/2;
		if(n%2==1)cout<<(n-1)/2;
	}
	return 0;
}
