#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,a[5005],m,C[5005][5005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n==3){
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]+a[1]>a[2])cout<<1;
        else cout<<0;
        return 0;
    }
    for(int i=1;i<=n;++i)cin>>a[i],m=max(m,a[i]);
    if(m==1){
        for(int i=1;i<=n+1;++i)C[i][1]=C[i][i]=1;
        for(int i=1;i<=n+1;++i)for(int j=2;j<i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
        for(int i=3;i<=n;++i)sum=(sum+C[n+1][i+1])%Mod;
        cout<<sum;
        return 0;
    }
    return 0;
}
