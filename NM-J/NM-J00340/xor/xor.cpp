#include<bits/stdc++.h>
using namespace std;
int n,num[500005]={},k,kn=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int n1=0,n0=0,n11=0;
	for(int i=0;i<n;i++){
		cin>>num[i];
		if(num[i]==1&&num[i-1]==1)n11++;
		if(num[i]==1)n1++;
		else n0++;
	}
	if(n1==n&&k==0)cout<<n/2;
	else if(k==1)cout<<n1;
	else cout<<n0+n11;
	return 0;
}

