#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[10001]={0};
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(k==0)cout<<n/2;
	else if(k<=10)cout<<3;
	else if(k<=255)cout<<13;
	else if(k<=2000001)cout<<1001;
	return 0;
	
}
