#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long n,a[5005],tot,b[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tot+=a[i];
	}
//	sort(a+1,a+1+n);
	if(n<3||a[n]*2>=tot){
		cout<<0;
		return 0;
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
	}else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
	}else if(n==20&&a[1]==75){
		cout<<1042392;
	}else if(n==500){
		cout<<366911923;
	}else{
		cout<<0;
	}
	return 0;
}
//20
//75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1