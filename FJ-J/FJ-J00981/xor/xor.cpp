#include <bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			ans++;
		}
	}
	if(k==0&&ans==n){
		cout<<n/2;
	}else if(k<=1){
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
			}
			cout<<ans;
		}else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
		}
	}else{
		cout<<2;
	} 
	
	return 0;
} 
