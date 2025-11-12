#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,c[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			c[i]=1;
		}
	}
	if(n<=1000){
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				long long sum=a[j];
				bool f=true;
				for(int l=j+1;l<=i;l++){
					if(c[l]==1){
						f=false;
						break;
					}
				}
				if(f){
					for(int l=j+1;l<=i;l++){
						sum^=a[l];
						c[l]=1;
					}
					if(sum==k){
						ans++;
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		if(k==0){
			for(int i=1;i<=n;i++){
				if(c[i]==c[i+1] && c[i]==0 && a[i]==a[i+1] && a[i]==1){
					ans++;
					c[i]=0;
					c[i+1]=0;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
