#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	if(a[1]+a[2]>a[3]*2) cout<<1;
	else cout<<0;
	return 0;
}
