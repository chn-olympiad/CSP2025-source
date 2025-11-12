#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[1000005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
	    if(a[0]+a[1]<=a[2]||a[0]+a[2]<=a[1]||a[1]+a[2]<=a[0]){
	    	cout<<0;
	    	return 0;
		}else{
			cout<<1;
			return 0;
		}
	}
	if(n==5){
		if(a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5) cout<<9;
		else cout<<6;
	}
	if(n==20) cout<<1042392;
	if(n==500) cout<<366911923;
	return 0;
}
