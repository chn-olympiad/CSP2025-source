#include<bits/stdc++.h>
using namespace std;
int n,ans,k;
int a[500005];
bool xza=1,xzb=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++; 
		}
		if(a[i]!=1){
			xza=0;
		}
		if(a[i]!=0&&a[i]!=1){
			xzb=0;
		}
	}
	if(xza==1){
		if(k==1){
			cout<<n;
			return 0;
		}
		if(k==0){
			cout<<n/2;
			return 0;
		}
		else{
			cout<<0;
		}
	}
	if(xzb==1){
		if(k!=0&&k!=1){
			cout<<0;
			return 0;
		}
		int st=0;
		for(int i=1;i<=n;i++){
			if(a[i]^st==k){
				ans++;
				st=0;
			}
			else{
				st^=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	int st=0,ans2=0;
	for(int i=1;i<=n;i++){
		if((a[i]^st)==k){
			ans2++;
			st=0;
		}
		else{
			st^=a[i];
		}
	}
	cout<<ans2;
	return 0;
}
