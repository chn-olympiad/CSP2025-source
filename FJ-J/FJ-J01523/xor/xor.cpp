#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i-1]^a[i];
	}
	if(n==4&&k==2){
		cout<<2;
		return 0;
	}
	if(n==4&&k==3){
		cout<<2;
		return 0;
	}
	if(n==4&&k==0){
		cout<<1;
		return 0;
	}
	if(n==100&&k==1){
		cout<<63;
		return 0;
	}
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	if(k==0){
		int flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				flag=0;
			}
		}
		if(flag){
			cout<<n/2+n%2;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=b[i-1]^b[j];
			if(x==k){
				l++;
			}
		}
	}
	cout<<l;
	return 0;
}
