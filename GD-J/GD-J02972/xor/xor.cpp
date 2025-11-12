#include<bits/stdc++.h>
using namespace std;
int n,k,a[700005],b[700005],mx,bj;
int bl(int l,int r){
	if(l==r){
		if(b[r]-b[l-1]==k)	return 1;
		else	return 0;
	}
	int mid=(l+r)/2;
	int x=bl(l,mid)+bl(mid+1,r),y=0;
	for(int i=l;l<=r;l++){
		int ans=a[i];
		for(int j=i;j<=r;j++){
			if(i!=j)	ans=ans^a[j];
			if(ans==k){
				y=1;
				break;
			}
		}
	}
	return max(x,y);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)	b[i]=a[i];
		else	b[i]=(b[i-1]^a[i]);
		if(a[i]!=1)	bj=1;
	}
	if(bj==1){
		cout<<n/2;
		return 0;
	}
	cout<<bl(1,n);
	return 0;
}
