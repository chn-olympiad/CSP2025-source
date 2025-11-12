#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long xor1(int i,int j){
	long long lr=0;
	for(int k=i;k<=j;k++){
		lr=lr^a[k];
	}
	return lr;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	long long ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	cout<<xor1(1,1);
//	cout<<xor1(2,4);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
	//		cout<<i<<" "<<j<<" ";
			if(xor1(i,j)==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 