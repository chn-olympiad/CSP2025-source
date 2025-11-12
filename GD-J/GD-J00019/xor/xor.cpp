#include<bits/stdc++.h>
using namespace std;
int a[500001],soa,sob,ans,n,k;
void solvea(){
	ans=n/2;
	return;
}
void solveb(){
	if(k==0){
		for(int i=0;i<n;i+=1){
			if(a[i]==0){
				ans++;
			}
			else{
				if(a[i+1]==1){
					ans++;
					i++;
				}

			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(a[i]==1)
			ans++;
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	cin>>k;	
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1){
			soa++;
			sob++;
		}
		else if(a[i]==0){
			sob++;
		}
	}
	if(soa==n){
		solvea();
	}
	else if(sob==n){
		solveb();
	}
	cout<<ans;
	return 0;
}


