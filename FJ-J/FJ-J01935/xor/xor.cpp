#include<iostream>
using namespace std;
int n,k;
int ans;
int maxnn;
int cnn;
int a[1000005];
int y[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxnn=max(maxnn,a[i]);
		if(a[i]==1){
			cnn++;
		}
	}
	if(maxnn==1){
		if(k==0){
			cout<<n-cnn<<endl;
		}
		else{
			cout<<cnn<<endl;
		}
		return 0;
	}
	int last=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=last;j--){
			y[i]^=a[j];
			if(y[i]==k){
				ans++;
				last=i+1;
			}
		} 
	}
	cout<<ans<<endl;
	return 0;
}

