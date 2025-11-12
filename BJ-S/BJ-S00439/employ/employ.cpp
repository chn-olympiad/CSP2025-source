#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=501,Mod=998244353;
int n,m,s[N],c[N],b[N],a[N][N],flag=1;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    for(int i=1;i<N;i++){
        a[i][0]=1;
        for(int j=1;j<=i;j++){
            a[i][j]=a[i][j-1]*(i-j+1)%Mod;
            //if(i<=100&&j<=100)cout<<i<<' '<<j<<' '<<a[i][j]<<'\n';
        }
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        s[i]=ch-'0';
        flag&=s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        flag&=(c[i]!=0);
    }
    if(flag)cout<<a[n][n]<<'\n';
    else if(n==m)cout<<"0\n";
    else{
        int ans=0;
        iota(b+1,b+n+1,1LL);
        do{
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(s[i]&&cnt>=c[b[i]]){
                    cnt++;
                }else if(!s[i])cnt++;
            }
            if(n-cnt>=m)ans++;
        }while(next_permutation(b+1,b+n+1));
        cout<<ans<<'\n';
    }
    return 0;
}