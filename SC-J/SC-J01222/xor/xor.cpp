#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(k==0){
		for(int i=1;i<=n;){
			if(a[i]==a[i+1]&&a[i+1]==1){
				ans++;
				i+=2;
			}
			if(a[i]==0){
				ans++;
				i++;
			}
		}
	}
	if(k==1){
		for(int i=1;i<=n;){
			if(a[i]==1){
				ans++;
				i+=1;
			}
		}
	}
	cout<<ans;
	return 0;
}