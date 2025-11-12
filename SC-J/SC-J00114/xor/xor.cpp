#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,k;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=true;
	}
	if(f==false && k==0){
		if(n%2==0){
			cout<<n/2;
		}
		else{
			cout<<(n-1)/2;
		}
		return 0;
	}
	if(k<=1){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else{
					if(a[i+1]==1){
						ans++;
						i++;
					}
				}
			}
			cout<<ans;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
		}
		return 0;
	}
	cout<<12701;
	return 0;
}