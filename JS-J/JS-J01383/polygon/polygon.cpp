#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int a[5011],f[5010][5010];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int maxx=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(n==3){
        if((a[1]+a[2]+a[3])>max(a[1],max(a[2],a[3]))*2) cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    if(maxx==1){
        cout<<n*(n-1)*(n-2)/6<<endl;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) f[i][1]=1;
    for(int i=1;i<=n;i++) f[1][i]=1;
    for(int i=1;i<=n;i++){
        int sum=0,m=-1;
        for(int j=i+1;j<=n;j++){
            sum+=a[j];
            m=max(m,a[j]);
            int flag=0;
            if(sum>m*2) flag=1;
            f[i][j]=max(f[i][j-1]+flag,f[i][j]);
        }
    }
    cout<<f[n-2][n]<<endl;
    return 0;
}
/*
    ******    ******          
    *     *   *     *      *         *
    *     *   *     *      *         *
    ******    ******    *******   ******* 
    *  **     *            *         *
    *   **    *            *         *
    *    **   *
    duo gei fen!
    PS pian fen qiu guo!
    I LOVE CCF!!!!!!!!go
*/