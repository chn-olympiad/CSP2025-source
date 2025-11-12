#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,h=0,max=0;
	cin>>n;
	int a[n]={0};
	if(n==3){
	    for(int i=0;i<n;i++){
		cin>>a[i];
		h+=a[i];
		if(max>a[i]){
			max=a[i];
		}
	    }
		if(h>max*2){
			cout<<1%998244353;
		}else{
			cout<<0;
		}	
	}
	return 0;
}
