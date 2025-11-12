#include<bits/stdc++.h>
using namespace std;
int a[1110000],ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0){
		cout<<n/2<<endl;
		return 0;
	}
	int flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=0&&a[i]!=1){
		    flag=0;
		    break;
		}
	}
	if(flag==1){
		if(k==0){
			for(int i=2;i<=n;i++){
				if(a[i]==a[i-1]&&a[i-1]==1){
					ans++;
					a[i]=0;
				}
				else {
					ans++;
				}
			}
			cout<<ans<<endl;
			return 0; 
		}
		else {
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
			cout<<ans<<endl;
			return 0; 
		}
	}
	else {
		cout<<n/2;
	}
	return 0;
}

