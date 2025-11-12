#include<bits/stdc++.h>
using namespace std;

int n,a[5010];
long long num = 0,x = 0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	x=a[1]+a[2]+a[3];
	if(x <= 2*a[3]) x+= a[4];
	for(int i=x;i<=n;i++){
		num+=n%x;
	}
	cout<<x%998244353;
    return 0;
}
