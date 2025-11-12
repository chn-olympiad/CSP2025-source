#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			a[i]=-1;
		}
	}
	if(k==0){
	   	int L=1;
	   	for(int R=1;R<=n;R++){
		if(L!=R&&a[L]==a[R]&&a[L]>=0&&a[R]>=0){
			ans++;
			L=R+1;
			R++;
		}else{
			a[R+1]=1;
			L++;
		}	
		}
	}else if(k==1){
	  int l=1;	
	  for(int r=1;r<=n;r++){
		if(r!=l&&a[l]!=a[r]&&a[l]>=0&&a[r]>=0){
			ans++;
			l=r+1;
			r++;
		}else{
			a[r]=0;
		}
	  }	
	}
	cout<<ans;
	return 0;
}
