#include<bits/stdc++.h>
using namespace std;
int n,k,a[2],ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==0){
			ans++;
		}
	}
	if(ans>0){
		cout<<ans;
		return 0;
	}
	if(n==2){
		if(a[0]==a[1]){
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
