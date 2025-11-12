#include<bits/stdc++.h>
using namespace std;

int main(){
	freeopen("xor.in","r",stdin);
	freeopen("xor.out","w",stdout);
	int n,k,sum=0,ans=0;
	cin>>n>>k;
	int a[100050];
	for(int i=1;i<=n;i++){
		cin>>a[i];      
		if(a[i]==1)sum++;
	}
	if(sum==n&&k==0){
		cout<<n/2;
	}
	
	return 0;
}