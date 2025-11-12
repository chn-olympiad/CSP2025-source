#include<bits/stdc++.h>
#define longlong unsigned long long
using namespace std;
longlong a[504],mol=998244353,f[1000][1000],b[1000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    memset(f,0,sizeof(f));
    f[0][0]=1;
    f[1][1]=1;
    f[1][0]=1;
    for(longlong  i=2;i<=500;i++){
        f[i][0]=1;
        f[i][i]=1;
        for(longlong j=1;j<i;j++){
            f[i][j]=f[i-1][j]+f[i-1][j-1];
        }
    }
    longlong  n,m,flag=0;
    cin>>n>>m;
    for(longlong  i=1;i<=n;i++){
        char s;
        cin>>s;
        a[i]=s-'0';
        if(a[i]==0)flag=1;
    }
    for(longlong i=1;i<=n;i++){
        cin>>b[i];

        if(b[i]==0)
            n--;
    }
    if(flag==1){
        cout<<0<<endl;
        return 0;
    }
    longlong ans=0;
    for(longlong  i=m;i<=n;i++){
     //       cout<<ans<<endl;
        ans=(ans+f[n][i]%mol)%mol;
    }
    cout<<ans<<endl;
    return 0;
}

