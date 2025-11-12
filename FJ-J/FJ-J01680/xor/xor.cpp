//xor.cpp
#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n,k,a[500005]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int zerox=0,onex=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) onex++;
		else if(a[i]==0) zerox++;
		if(a[i]==k) ans++;
	}
	if(k==0) cout<<zerox;
	else if(k==1) cout<<onex;
	else cout<<ans;
	return 0;
}
