#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int cnt1,cnt0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt1++;
		else if(a[i]==0) cnt0++;
	}
	if(k==0){
		ans=cnt1/2+cnt0;
	}
	else{
		ans=cnt1;
	}
	cout<<ans;
	return 0;
}