#include<bits/stdc++.h>
using namespace std;
int a[21];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<0;
		return 0;
	}
	if(n==3){
		sort(a+1,a+1+3);
		if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
		else cout<<0;
		return 0;
	}
    return 0;
}
