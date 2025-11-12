#include<bits/stdc++.h>
using namespace std;
const int N=5003,M=998244353;
int n,a[N],f[N][N],res;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<N;j++){
            f[i][j]=f[i-1][j];
            if(j>=a[i])f[i][j]=(f[i][j]+f[i-1][j-a[i]]>=M?f[i][j]+f[i-1][j-a[i]]-M:f[i][j]+f[i-1][j-a[i]]);
            else f[i][j]=(f[i][j]+f[i-1][0]>=M?f[i][j]+f[i-1][0]-M:f[i][j]+f[i-1][0]);
        }
    }
    for(int i=1;i<=n;i++)res=(res+f[i-1][a[i]+1]>=M?res+f[i-1][a[i]+1]-M:res+f[i-1][a[i]+1]);
    cout<<res;
    return 0;
}