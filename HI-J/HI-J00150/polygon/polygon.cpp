#include<bits/stdc++.h>
using namespace std;
int n;
int a[5020];

int ans=0;
void x(int h,int l,int d){
	
	for(int i=l;i<n;i++){
		//h=h+a[i];
		if(h+a[i]>a[i]*2&&d>1)ans++;
		
		
		x(h+a[i],i+1,d+1);
		
		
		ans=ans%998244353;
		//h=h-a[i];
	}
	return;
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	x(0,0,0);

	
	cout<<ans;
	return 0;
}
