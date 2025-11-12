#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k,cnt1=0,cnt2=0;cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			cnt1++;
		}else if(a[i]==0){
			cnt2++;
		}
	}
	if(k==0){
		cout<<cnt1/2+cnt2;
	}
	if(k==1){
		cout<<cnt1;
	}
	return 0;
}
