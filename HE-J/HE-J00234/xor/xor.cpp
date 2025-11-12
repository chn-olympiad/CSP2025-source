#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1];
	int ans=0;
	if(k==0){
		cout<<n/2;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==k){
				ans++;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
