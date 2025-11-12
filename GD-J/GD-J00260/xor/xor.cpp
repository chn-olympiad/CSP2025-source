#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0;
int main(){
	freopen("xor","r",stdin);
	freopen("xor","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==k) ans++;
	} 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
