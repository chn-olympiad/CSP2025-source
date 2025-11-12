#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0){
		int a[n+1];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[i]==0){
				ans++;
			}else if(i!=n-1&&a[i+1]==1){
				a[i+1]=0;
			}
		}
		cout<<ans;
	}else{
		int ans=0,x;
		for(int i=0;i<n;i++){
			cin>>x;
			if(x==1){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
