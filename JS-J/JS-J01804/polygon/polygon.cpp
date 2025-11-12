#include <bits/stdc++.h>
using namespace std;
//include <bits/std
int a[5001],f[5001][5001],pre[5001][5001],jx[5001];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
            //cout<<a[i]<<endl;
        int y=a[i]*2;
        int z=i;
        for(int j=i;j<=n;j++){
            if(a[j]>=y)break;
            z=j;
        }
        jx[i]=z;
       // cout<<z<<' ';
        f[1][jx[i]]+=1;
    }
    for(int i=1;i<=n;i++){
        pre[1][i]=pre[1][i-1]+f[1][i];
      //  cout<<pre[1][i]<<endl;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){


            f[i][j]=pre[i-1][jx[j]]-pre[i-1][j];

           // if(a[j+1]==a[j])f[i][j]=pre[i-1][jx[j]]-pre[i-1][j-1];
            f[i][j]%=998244353;;//cout<<pre[i-1][jx[i]]<<' '<<jx[i]<<i<<' '<<pre[i-1][n]<<endl;;
        }

        for(int j=1;j<=n;j++){
            pre[i][j]=pre[i][j-1]+f[i][j];
          //  cout<<pre[i][j]<<' '<<i<<' '<<j<<' '<<endl;;
            pre[i][j]%=998244353;
        }
    }
    int ans=0;
    for(int i=3;i<=n;i++){
        ans+=pre[i][n];
       // cout<<pre[i][n]<<endl;
        ans%=998244353;
    }
    cout<<ans<<endl;
}
//bei T3 dang chen hei man ba zhou fei le!!!
