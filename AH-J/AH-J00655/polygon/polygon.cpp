#include<bits/stdc++.h>
using namespace std;
int m,a[100005],dp[100005],ans;

int main(){
    freopen("polygon.in","r",stdin);
    cin>>m;
    freopen("polygon,out","w",stdout);
    if(m<3) {
	cout<<0;
	return 0;
    }
    else {
	for(int i=1;i<=m;i++){
	    cin>>a[i];
	}
	for(int i=3;i<=m;i++){
	}
	cout<<ans%998244353;
    }
    return 0;
}
