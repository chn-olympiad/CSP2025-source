#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
bool f=0,b=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			f=1;
		}
		if(a[i]!=1&&a[i]!=0){
			b=1;
		}
	}
	if(f==0&&k==0){
		cout<<n/2;
		return 0;
	}
	if(b==0){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		if(k==1){
			cout<<ans;
		}
		else{
			cout<<ans/2;
		}
		return 0;
	}
	ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
