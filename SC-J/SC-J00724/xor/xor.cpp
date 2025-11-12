#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],res,sh;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			sh++;
		}
	}
	if(sh==n){
		if(k==1){
			for(int i=2;i<=n;i++){
				res+=(i-1)*i/2;
			}
			cout<<res;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	
	for(int i=1;i<=n-1;i++){
		int s=a[i];
		if(a[i]==k){
			res++;
		}
		for(int j=i+1;j<=n;j++){
			s=s|a[j];
			if(s==k){
				res++;
			}
		}
	}
	cout<<res;
	return 0;
}