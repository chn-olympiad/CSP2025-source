#include<bits/stdc++.h>
using namespace std;
int check[500010];
int a[500010];
int q(int l,int r){
	int x=a[l];
	if(l==r){
		return x;
	}
	for(int i=l+1;i<=r;i++){
		if(x>a[i]){
			x+=a[i];
		}else{
			x=a[i]-x;
		}
	}
	return x;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	bool c=true;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(q(i,j)==k){
				for(int p=i;p<=j;p++){
					for(int h=0;h<n;h++){
						if(p==check[h]){
							c=false;
						}
					}
				}
				if(c){
					ans++;
					for(int y=i;y<=j;y++){
						check[y]=y;
					}
				//	cout<<i<<" "<<j<<endl;
				}
				c=true;
			}
		}
	}
	if(q(0,0)==k){
		ans++; 
	}
	cout<<ans;
	return 0;
}
