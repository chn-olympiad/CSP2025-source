#include<bits/stdc++.h>
using namespace std;
bool cmp(int b1,int b2){
	return b1>=b2;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],f=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(k==0&&f==0){
		cout<<n/2;
	}
	else if(k==1){
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[i]!=a[i+1]){
				ans++;
				i++;
			}
		}
		cout<<ans;	
	}
	else if(k==0){
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[i]==a[i+1]){
				ans++;
				i++;
			}
		}
		cout<<ans;	
	}
	return 0;
}
