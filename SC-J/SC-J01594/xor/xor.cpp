#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	bool w_a=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0) w_a=0;
	}
	if(k==0&&w_a){
		cout<<n/2;
	}
	else if(k<=1){
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[i]==1) ans++;
		}
		if(k==1){
			cout<<ans;
		}
		else cout<<n-ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}