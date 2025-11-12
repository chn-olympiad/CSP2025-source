#include <bits/stdc++.h>
using namespace std;
int a[1000100],n,k,ans;
int main()
{
	freopen("xor.in","r",FILE);
	freopen("xor.out","w",FILE);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){ 
		if(a[i]==k){
			ans++;
		}
	}
	cout<<ans;
	return 0; 
}
