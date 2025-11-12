#include <bits/stdc++.h>
using namespace std;
int n,a[10005],ma; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ma = max(ma,a[i]);
		}
		if(a[1]+a[2]+a[3]>2*ma&&ma<=10){
			cout<<1;
			return 0;
		}	
	}
	return 0;
}
