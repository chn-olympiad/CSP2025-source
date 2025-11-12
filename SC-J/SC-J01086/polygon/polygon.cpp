#include<bits/stdc++.h>
using namespace std;
//RP++
int n,a[11451];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(abs(a[0]-a[1])<a[2]&&a[0]+a[1]>a[2]) cout<<1;
	}
	return 0;
}
