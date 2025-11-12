#include<bits/stdc++.h>
using namespace std;
int n,a[5005],x,y;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		x+=a[i];
		if(a[i]>y) y=a[i];
	}
	if(x>y*2) cout<<1;
	else cout<<0;
	return 0;
}
