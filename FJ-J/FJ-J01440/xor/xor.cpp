#include<bits/stdc++.h>
using namespace std;
int b[10001]={0,1,3,6,10,15,21,28,36,45,55,66,78,91};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100001];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1)cout<<a[1];
	else if(k==0){
		int sum=0;
		for(int i=1;i<=n;i++){
			b[i]=b[i-1]+i;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0)sum++;
		}
		if(sum==0)puts("0");
		else cout<<b[sum];
	}
	else if(k==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			b[i]=b[i-1]+i;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==1)sum++;
		}
		if(sum==0)puts("0");
		else cout<<b[sum];
	}
	return 0;
}
