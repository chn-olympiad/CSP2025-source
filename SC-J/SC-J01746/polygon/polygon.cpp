#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3) cout<<0;
	
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
		else cout<<0;
	}
	if(n>3){
		for(int i=3;i<=n;i++){
			s+=n-i+1;
		} 
		cout<<s;
	}
	return 0;
}