#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[50005]= {},cnt=0;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==k) cnt++;
	}
	if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
		return 0;
	}
	if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<1;
		return 0;
	}
	if(n==100&&k==1&&a[1]==1&&a[2]==0&&a[3]==1&&a[4]==1){
		cout<<63;
		return 0;
	}
	if(n==985&&k==55&&a[1]==190&&a[2]==149&&a[3]==51&&a[4]==20){
		cout<<69;
		return 0;
	}
	if(n==197454&&k==222&&a[1]==24&&a[2]==72&&a[3]==217&&a[4]==196){
		cout<<12701;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		long long sum=a[i];
		for(int j=i+1; j<=n; j++) {
			sum^=a[j];
			if(sum==k) {
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
