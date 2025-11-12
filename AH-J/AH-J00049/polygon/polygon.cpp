#include<bits/stdc++.h>
using namespace std;
int n,i,a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
		cin>>a[i];
    }
    if(a[1]+a[2]>a[3]){
		if(a[1]+a[3]>a[2]){
			if(a[3]+a[2]>a[1]){
				cout<<'1';
				return 0;
			}
		}
    }
    cout<<'0';
    return 0;
}
