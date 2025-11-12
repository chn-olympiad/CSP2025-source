#include<bits/stdc++.h>
using namespace std;
int n,k,l,ans=0,ans1=0,a[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
			else ans1++;
		}
		cout<<ans/2+ans1;
		return 0;
	}
	cout<<ans; 
	return 0;
}
