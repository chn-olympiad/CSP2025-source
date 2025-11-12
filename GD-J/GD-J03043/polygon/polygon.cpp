#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n,a[5005],aall=0,amax=-999;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		aall+=a[i];
		if(a[i]>amax)amax=a[i];
	}
	if(n==3&&aall>2*amax)cout<<1;
	else cout<<0;
	return 0;
}
