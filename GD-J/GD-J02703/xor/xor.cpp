#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000070],k,ans;
bool l=1,y=1,j;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) y=0;
		if(a[i]!=0&&a[i]!=1) l=0;
	}
	if(y==1&&k==0) cout<<n/2;
	else if(y==1&&k==1) cout<<n;
	else if(l==1) {
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					j++;
					if(j==2){
						ans++;
						j=0;
					}
				}
				else {
					ans++;
					j=0;
				}
			}
		cout<<ans;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
		cout<<ans;
		}
	}
	return 0;
} 
