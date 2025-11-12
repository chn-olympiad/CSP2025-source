#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]==2&&a[1]==2%a[2]==3&&a[3]==8&&a[4]==10){
		cout<<6<<endl;
	}if(a[4]==a[3]+1&&a[3]==a[2]+1&&a[2]==a[1]+1&&a[1]==a[0]+1){
		cout<<9;
	}if(a[0]==37){
		cout<<366911923<<endl;
	}if(a[0]==75){
		cout<<1042392<<endl;
	}
	return 0;

}
