#include<bits/stdc++.h>
using namespace std;
int n,a[5006];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		cout<<n-2;
	}
	else{
		if(a[1]+a[2]>mx&&a[2]+a[3]>mx&&a[1]+a[3]>mx){
			cout<<1;
		}
		else cout<<0;
    }
}