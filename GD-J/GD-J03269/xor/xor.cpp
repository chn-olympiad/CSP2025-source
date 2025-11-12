#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s[500005],f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1] xor a[i]);
		if(a[i]!=a[i-1]&&i!=1){
			f=1;
		}
	}
	if(f==0){
		if(k==a[1]){
			cout<<n;
		}
		else if(k==0){
			cout<<n/2;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j] xor s[i-1])==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
