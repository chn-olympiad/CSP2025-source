#include<iostream>
using namespace std;
const int m=5e5+5;
int n,k;
int a[m];
int cal(int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){
		ans^=a[i];
	}
	return ans;
}
int finda(int l){
	int r=n+1;
	for(int i=l;i<=r;i++){
		for(int j=i;j<=r;j++){
			if(cal(i,j)==k&&j<r){
				r=j;
			}
		}
	}
	return r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(finda(i)<=n){
			ans++;
		}
		i=finda(i);
	}
	cout<<ans;
	return 0;
}
