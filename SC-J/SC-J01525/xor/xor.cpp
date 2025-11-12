#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	if(k==0){
		for(int i=0;i<n;i++){
			if(a[i]==0)ans++;
			if(a[i]==1){
				if(i+1<n){
					ans++;i++;
				}	
			}
		}
	}
	if(k==1){
		for(int i=0;i<n;i++)if(a[i]==1)ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}