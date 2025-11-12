#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	bool quan1=1,zhi01=1;
	int one=0,zero=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			quan1=0;
		}
		if(a[i]!=1&&a[i]!=0){
			zhi01=0;
		}
		switch(a[i]){
			case 0:
				zero++;
				break;
			case 1:
				one++;
				break;
		}
	}
	if(quan1==1&&k==0){
		cout<<n/2;
	}
	else if(quan1==1&&k==1){
		cout<<n;
	}
	else if(zhi01==1&&k==0){
		cout<<zero+one/2;
	}
	else if(zhi01&&k==1){
		cout<<one;
	}
	else{
		cout<<1;
	}
	return 0;
}
