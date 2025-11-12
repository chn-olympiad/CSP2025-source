#include<bits/stdc++.h>
using namespace std;
int i,j,l,n,l,p,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
	for(i=3;i<=n;i++){
        for(j=i;j>=1;j--){
			l*=j;
		}
        for(j=n;j>=n-i;j++){
			p*=j;
		}
		ans+=p/l;
    }
    cout<<ans;
    return 0;
}
