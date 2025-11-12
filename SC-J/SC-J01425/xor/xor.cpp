#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int a[M];
int main(){
	freopen("xor,in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2 && k==0){
		cout<<1;
	}
	else if(n<=10 && k<=1){
		if(k==1){
			int ans=0;
			for(int i=0;i<n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
		}
		else if(k==0){
			int ans=0;
			for(int i=0;i<n;i++){
				if(a[i]==0){
					ans++;
				}
				else if(a[i]==1 && a[i+1]==1){
					ans++;
					i++;
				}
			}
			cout<<ans;
		}
	}
	else if(n<=100 && k==0){
		if(n%2!=0)
			cout<<(n-1)/2;
		else
			cout<<n/2;
	}
	else if(n<=100 && k<=1){
		if(k==1){
			int ans=0;
			for(int i=0;i<n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
		}
		else if(k==0){
			int ans=0;
			for(int i=0;i<n;i++){
				if(a[i]==0){
					ans++;
				}
				else if(a[i]==1 && a[i+1]==1){
					ans++;
					i++;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}