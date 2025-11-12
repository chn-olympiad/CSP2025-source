#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long c[500005];
long long max1[500005];
long long yhh(int l,int r){
	long long ans;
	if(r==l){
		return c[r];
	}
	if(r-l==1){
		return c[l]^c[r];
	}
	ans=c[l]^c[l+1];
	for(int i=l+2;i<=r;i++){
		ans=ans^c[i];
	} 
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=i;j++){
			if(yhh(j,i)==b){
				max1[i]=max(max1[j-1]+1,max1[i]);
			}
		} 
	}
	cout<<max1[a];
} 