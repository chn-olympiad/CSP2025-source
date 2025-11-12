#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag1=1,flag2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag1=0;
		if(a[i]>1)flag2=0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else if(a[i+1]==a[i]&&i<n){
				ans++;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
			else if(a[i+1]-a[i]==1&&a[i+1]%2==1&&i<n||a[i]-a[i+1]==1&&i<n&&a[i]%2==1){
				ans++;
				i++; 
			}
		}
		cout<<ans;
		return 0;
	} 
	cout<<0;
	return 0;
}
