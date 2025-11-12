#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,ans,arr[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdin);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]==k)ans++;
	}
	cout<<ans;
	return 0;
}