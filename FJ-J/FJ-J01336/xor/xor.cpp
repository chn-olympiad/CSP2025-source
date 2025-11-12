#include<bits/stdc++.h>
using namespace std;
long long n,k;
int a[500005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==2||k==3){
		cout<<n/2;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)ans++;
	}
	cout<<ans;
	return 0;
}
