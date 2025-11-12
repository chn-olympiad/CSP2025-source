#include<bits/stdc++.h>
using namespace std;
int n,m;
char s;
int c[505],a[505],sss[20];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s,a[i]=(int)(s-'0');
    for(int i=1;i<=n;i++)cin>>c[i];
    if(m==1){
        int iiii=-1;
        for(int i=1;i<=n;i++)if(a[i]==1)iiii=i;
        if(iiii==-1){
            cout<<0;
            return 0;
        }
        sort(c+1,c+n+1);
        int i;
        for(i=1;i<=n;i++)if(c[i]>=iiii)break;
        long long ans=1;
        while(n-1>=0){
            ans*=n;
            ans=ans%998244353;
            n--;
        }
        cout<<ans;
        return 0;
    }
    if(n==m){//5
        for(int i=1;i<=n;i++)if(a[i]==0){
            cout<<0;
            return 0;
        }
        long long ans=1;
        while(n-1>=0){
            ans*=n;
            ans=ans%998244353;
            n--;
        }
        cout<<ans<<endl;
    }
    bool isA=true;
    for(int i=1;i<=n;i++)if(a[i]==0){
        isA=false;
        break;
    }
    if(isA){
        long long ans=1;
        while(n-1>=0){
            ans*=n;
            ans=ans%998244353;
            n--;
        }
        cout<<ans<<endl;
        return 0;
    }
}
