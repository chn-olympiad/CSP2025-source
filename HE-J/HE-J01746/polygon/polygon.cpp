#include<bits/stdc++.h>
using namespace std;
int n,a[5005],h,r,i;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	h=(a[1]+a[i])*n/2;
	for(int i=1;i<=n;i++){
		if(h>max(a[1],a[i])*2){
			r++;
		}
	}
	cout<<r;
}
