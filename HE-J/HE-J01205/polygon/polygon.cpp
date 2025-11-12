#include<bits/stdc++.h>
using namespace std;
long long a[5001],n,a1,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3 && a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
    	cout<<1;
    	return 0;
	}
	else cout<<0;
	return 0;
}
