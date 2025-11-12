#include<bits/stdc++.h>
using namespace std;
int n,k,a[600000],cnt1,cnt2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt1++;
		else if(a[i]==0) cnt2++;
	}
	if(k==0){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1 && a[i+1]==1){
				i+=2;
				sum++;
			}
		}
		cout<<sum+cnt2;
	}else if(k==1){
		cout<<cnt1;
	}
	return 0;
}
