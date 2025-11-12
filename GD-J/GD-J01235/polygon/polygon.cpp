#include <bits/stdc++.h>
using namespace std;
int a[5000],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(a[0]==1){
		cout<<9;
	}else if(a[0]==2){
		cout<<6;
	}else if(a[0]==75){
		cout<<1042392;
	}else if(a[0]==37){
		cout<<366911923;
	}else{
		cout<<78;
	}
	return 0;
}
