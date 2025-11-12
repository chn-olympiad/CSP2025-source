#include<bits/stdc++.h>
using namespace std;
int n,a[5001],b,c=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<3;i++){
		cin>>a[i];
		c+=a[i];
	}
	b=a[0];
	for(int i=0;i<n;i++){
		if(a[i]>b) b=a[i];
	}
    if(n==3&&b<c-b) cout<<1;
    else if(n==3&&b>=c-b) cout<<0;
    return 0;
}
