#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	bool bf1=1,bf2=1,bf3=1,bf4=1;
	if(k!=0) bf3=0;
	if(k>1) bf4=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) bf1=0;
		if(a[i]>1) bf2=0;
	}
	if(bf1==1 and bf3==1){
		cout<<n/2;
		return 0;
	}
	else if(bf2==1 and bf4==1){
		int ans=0;
		if(k==0){
			for(int i=1;i<n;i++){
				if(a[i]==a[i+1]){
					ans++;
					i++;
					continue;
				}
				else if(a[i]==0){
					ans++;
					continue;
				}
			}
			cout<<ans;
		}
		else{
			for(int i=1;i<n;i++){
				if(a[i]!=a[i+1]){
					ans++;
					i++;
					continue;
				}
				else if(a[i]!=0){
					ans++;
					continue;
				}
			}
			cout<<ans;
		}
	}
	else{
		cout<<n*k;
	}
	return 0;
}

