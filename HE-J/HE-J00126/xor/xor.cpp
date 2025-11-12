#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,k;
long long a[N];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i+=2){
		if((a[i]^a[i+1])==k) ans++;
	}
	cout<<ans;
	return 0;
}
