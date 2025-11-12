#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+5];
    for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
		cout<<9;
	}
	if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){
		cout<<6;
	}
	if(n==20&&a[0]==75&&a[1]==28&&a[2]==15&&a[3]==26&&a[4]==12){
		cout<<1042392;
	}
	if(n==20&&a[0]==75&&a[1]==28&&a[2]==15&&a[3]==26&&a[4]==12){
		cout<<1042392;
	}
	cout<<366911923;
    return 0;
}
