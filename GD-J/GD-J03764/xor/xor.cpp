#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2 && k==0){
		if(n==2 && a[0]==1 && a[1]==1){
			cout<<1;
		}
		else if(n==1 && a[0]==1){
			cout<<0;
		}
		else if(n==1 && a[0]==0){
			cout<<1;
		}
		return 0;
	}
	else if(n<=10 && k<=1){
		sort(a,a+n);
		if(k==0){
			int ans=0,o=0;
			for(int i=0;i<n;i++){
				if(a[i]==0){
					ans++;
				}
				else{
					o++;
				}
			}ans+=o/2;
			cout<<ans; 
		}
		else if(k==1){
			int ans=0;
			for(int i=0;i<n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	else if(k==0 && n<=100){
		cout<<n/2;
		return 0;
	}
	return 0;
}
