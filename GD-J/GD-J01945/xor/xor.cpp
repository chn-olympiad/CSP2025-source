#include<bits/stdc++.h>
using namespace std;
int c[500005];
int myxor(int x,int y){
	int a[30]={},b[30]={},sza=0,szb=0,xorv=0;
	while(x>0){
		a[sza++]=x%2;
		x/=2;
	}
	for(int i=0;i<sza;i++) swap(a[i],a[sza-i-1]);
	while(y>0){
		b[szb++]=y%2;
		y/=2;
	}
	for(int i=0;i<szb;i++) swap(b[i],b[szb-i-1]);
	int mxsz=max(sza,szb),w=1;
	for(int i=0;i<mxsz;i++){
		if(a[i]!=b[i]) xorv+=w;
		w*=2;
	}
	return xorv;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,cnum0=0,cnum1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>c[i];	
		if(c[i]>0) cnum1++;
		else cnum0++;
	}
	if(k>0) cout<<cnum1;
	else if(k==0 && cnum1!=n) cout<<max({n/2,cnum0,cnum0+cnum1/2});
	else if(k==0 && cnum1==n) cout<<n/2;
}
