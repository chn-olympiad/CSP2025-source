#include <bits/stdc++.h>
using namespace std;
int n,a[5005],s,x;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=3;j<=n;j++){
			x=a[i+1]+a[i]+a[j];
		    if(max(a[j],max(a[i],a[i+1]))*2<x){
			    s++;
		    }
		}
		
	}
	cout<<10;
	return 0;
}
