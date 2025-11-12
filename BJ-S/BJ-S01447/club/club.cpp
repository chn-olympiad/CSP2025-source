#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define endl '\n'
using namespace std;
int t,n,a[100005][4],b[100005],f[205][205][205],ans;
bool casea,caseb;
int main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--){
        casea=caseb=true,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) for(int j=1;j<=3;j++){
            cin>>a[i][j];
            if(j==3 and a[i][j]) casea=caseb=false;
            if(j==2 and a[i][j]) casea=false;
        }
        if(n<=200){
            memset(f,0,sizeof(f));
            for(int i=1;i<=n;i++) for(int j=0;j<=n/2;j++) for(int k=0;k<=n/2;k++) if(0<=i-j-k and i-j-k<=n/2){
                if(j!=0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
                if(k!=0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
                if(i-j-k!=0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
            }
            for(int i=0;i<=n/2;i++) for(int j=0;j<=n/2;j++) if(n-i-j<=n/2) ans=max(ans,f[n][i][j]);
            cout<<ans<<endl;
        }else if(casea){
            for(int i=1;i<=n;i++) b[i]=a[i][1];
            sort(b+1,b+n+1,[](int a,int b){return a>b;});
            for(int i=1;i<=n/2;i++) ans+=b[i];
            cout<<ans<<endl;
        }
    }
    return 0;
}