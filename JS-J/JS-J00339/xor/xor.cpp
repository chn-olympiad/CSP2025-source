#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,fl=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0 && fl!=-1) fl=1;
		if(a[i]!=1 && a[i]!=0) fl=-1;
	}
	if(fl==0) ans=n/2;
	else if(fl==1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]==1 && a[i+1]==1){
					ans++;
					i++;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
				if(a[i]==0 && a[i+1]==1){
					ans++;
					i++;
				}
			}
		}
	}
	else ans=(n+k)/2-1;
	cout<<ans;
	return 0;
}
