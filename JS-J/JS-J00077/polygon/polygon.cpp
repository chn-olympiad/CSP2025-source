#include<bits/stdc++.h>
using namespace std;
long long c[5005][5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        c[i][1]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=i;j++){
            c[i][j]=c[i][j-1]*c[i][j-2]%998244353;
        }
    }
    long long ans=1;
    for(int i=3;i<=n;i++){
        ans+=c[n][i];
        ans%=998244353;
    }
    cout<<ans;
	return 0;
}
