#include<bits/stdc++.h>
using namespace std;
int a[5005];
int mx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
 	int n;
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	}
	if(n<=3){
		mx=max(a[1],a[2]);
		mx=(mx,a[3]);
		int sum=a[1]+a[2]+a[3];
		if(mx*2<sum){
			cout<<1;
		}
	}
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	return 0;
}