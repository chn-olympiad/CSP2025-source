#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
	long long a[n+5];
	for(long long i=0;i<n;i++) cin>>a[i];
	bool f=true;
	for(int i=0;i<n;i++){
		if(a[i]!=1) f=false;
	}
	if(f){
		cout<<n/2;
	}
	return 0;
}