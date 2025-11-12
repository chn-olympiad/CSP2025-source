#include<bits/stdc++.h>
using namespace std;

int n,k,a[50001],ans,f=1;

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(k==0){
		if(f==1)  cout<<n/2;
		else{
			int z[50001],i=1;
			for(int j=1; j<=n; j++){
				if(a[j]==0)ans++;
				else if(i!=1){
					ans++;
					i--;
				}
				else{
					z[i]=1;
					i++;
				}
			}
			cout<<ans;
		}
	}
	else if(k==1){
		for(int i=1; i<=n; i++){
			if(a[i]==1)  ans++;
		}
		cout<<ans;
	}
	
	return 0;
}