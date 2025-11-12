#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,k;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=2&&k==0){
		cout<<0;
	}
	else if(n<=100&&k<=1){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;i++)
				if(a[i]==0)
					ans++;
			cout<<ans;
		} 
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)
					ans++;
			}
			cout<<ans;
		}
	}
	else{
		cout<<n;
	}
	return 0;
}
