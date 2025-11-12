#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,o;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k>1&&(a[1]==0||a[1]==1)&&(a[2]==0||a[2]==1)){
		cout<<0;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			if(a[i]==1&&a[i+1]==1){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		//	cout<<a[i]<<" ";
		}else{
			o=a[i]^a[i+1];
			if(o==k&&a[i+1]!=k&&a[i]!=-1&&a[i+1]!=-1){
				ans++;
			//	cout<<o<<" ";
				a[i]=-1;
				a[i+1]=-1;
			}
		}
	}
	cout<<ans;
	return 0;
} 