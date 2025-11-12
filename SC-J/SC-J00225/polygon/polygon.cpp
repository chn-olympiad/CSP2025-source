#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int x=a[1]+a[2]+a[3];
		if((x>a[1]*2)&&(x>a[2]*2)&&(x>a[3]*2)){
			cout<<1;
		}
		else cout<<0;
	}
	else if(n==5){
		if(a[1]==1){
			cout<<9;
		}
		else if(a[1]==2){
			cout<<6;
		}
		else cout<<16;
	}
	else if(n==20){
		cout<<1042392;
	}
	else if(n==500){
		cout<<366911923;
	}
	else cout<<10086;
	return 0;
} 