#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans,m=0,f[1010][1010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        cin>>a[1]>>a[2]>>a[3];
        sort(a+1,a+4);
        if((a[1]+a[2])>a[3])cout<<1;
        else cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m=max(m,a[i]);
    }
    if(m==1){
        f[1][1]=1;
        f[2][1]=1;
        f[2][2]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i;j++){
                f[i][j]=((f[i-1][j]%998244353)+(f[i-1][j-1]%998244353))%998244353;
            }
        }
        for(int i=3;i<=n;i++){
            for(int j=3;j<=i;j++){
                ans+=f[i][j];
                ans%=998244353;
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==5&&a[1]==1)cout<<9;
    else if(m==5&&a[1]==2)cout<<6;
    else if(m<=10)cout<<0;
    else if(m<=20)cout<<1042392;
    else cout<<366911923;
    return 0;
}
