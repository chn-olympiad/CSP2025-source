#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,sum=0;
	cin>>n>>k;
	long long a[n+1];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(k==0){
		cout<<1<<endl;
		return 0;
	}
	else if(k<=n-2){
		cout<<a[1]<<endl;
		return 0;
	}
	else cout<<sum<<endl;
	
	
	
	return 0;
}
