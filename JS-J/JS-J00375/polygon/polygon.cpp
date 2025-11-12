#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,ma;
void dg(int w,int x,int y,int z,bool is){
	if(w>=3 && y*2<z && is==1){
		ans++;
		ans%=998244353;
		//cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
	}
	if(x==n+1){
		return;
	}
	dg(w+1,x+1,a[x],z+a[x],1),dg(w,x+1,y,z,0);
}
int pw(int x){
	if(x==0){
		return 1;
	}
	int z=pw(x/2);
	if(x%2==0){
		return z*z%998244353;
	}
	return z*z%998244353*2%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(ma==1){
		cout<<pw(n)-n*(n-1)/2-n-1;
		return 0;
	}
	sort(a+1,a+n+1);/*
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	dg(0,1,0,0,1);	
	cout<<ans;
	return 0;
}
