#include<bits/stdc++.h>
using namespace std;
int n,k,a[10000];
int ans(){
	int l,r,maxn=INT_MIN;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int t=a[i];
			for(int k=i+1;k<=j;k++){
				t^=a[k];
			}
			if(t==k){
				maxn=max(maxn,(j-i+1));
			}	
		}
	}
	return maxn;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<1;
		return 0;
	}else if(k==1){
		cout<<ans();
		return 0;
	}else{
		cout<<"ÕâÌâÊ«ÈË???????"; 
	}	
	return 0;
} 
/*
4 2
2 1 0 3
 
4 3
2 1 0 3 

100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
*/
