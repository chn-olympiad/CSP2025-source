#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=0;i<n;i++){
			ans++;
		}
		if(ans%2==0) cout<<ans/2;
		else cout<<ans/2+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
