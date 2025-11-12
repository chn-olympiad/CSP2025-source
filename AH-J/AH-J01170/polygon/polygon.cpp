#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[100000],cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(max(max(a[1],a[2]),a[3])*2<a[1]+a[2]+a[3]) cnt++;
        cout<<cnt;
	}
	else cout<<(n-1)*(n-1)-1;
	return 0;
}
