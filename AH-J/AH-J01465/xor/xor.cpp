#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,cnt1,cnt0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		 cin>>a[i];
		 if(a[i]==1) cnt1++;
		 else cnt0++;
	 }
	if(k==1){
		cout<<cnt;
	}
	else if(k==0){
		cout<<cnt0+cnt1/2;
	}
	return 0;
}
