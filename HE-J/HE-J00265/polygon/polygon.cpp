#include<bits/stdc++.h>
using namespace std;
int n,a[5100],h,ans;
int c(int e,int b,int f){
	cout<<e<<" "<<b<<" "<<f<<" "<<h<<"\n";
	int g;
	if(e==0&&b>h){
		ans++;
		return 0;
	}
	for(int j=f+1;j<n;j++){
		if(b<=h){
			h=g;
		}
		g=h;
		h=max(h,a[j]);
		c(e-1,b+a[j],j);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=3;k<=n;k++){
		c(k,0,0);
	}
	cout<<ans+1;
	return 0;
} 


