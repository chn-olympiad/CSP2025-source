#include<bits/stdc++.h>
using namespace std;
int x[10000007];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(x[i]==0){
				ans++;
			} 
		}
		cout<<ans;
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(x[i]==1){
				ans++;
			} 
		}
		cout<<ans;
	}
	else{
		return 0;
	}
}
