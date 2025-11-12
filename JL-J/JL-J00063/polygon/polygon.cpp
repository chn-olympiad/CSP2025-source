#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
//#define int long long
int n,lst=0;
int a[5555];
int jc(int n){
    int ans=1;
    while(n>1){
        ans*=n;
        ans%=mod;
        n--;
    }
}
void work(int s,int all,int maxn,int now){
    if((all>maxn+maxn)&&(now>2))lst++;
    for(int i=s+1;i<=n;i++){
        work(i,all%mod+a[i]%mod,max(maxn,a[i]),now+1);
    }
}
int C(int m,int n){
    if(m==n)return 1;
    return (jc(m)/jc(m-n))/jc(n);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    bool all1=true,alllk=true;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1&&all1)all1=false;
        if(a[i]!=a[1]&&alllk)alllk=false;
    }
    if(n==3){
        if(a[1]+a[2]>a[3] && a[2]+a[3]>a[1] && a[1]+a[3]>a[2]){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }
    if(all1||alllk){
        int ans=0;
        for(int i=n;i>=3;i--){
            ans+=C(n,i);
            ans%=mod;
        }cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        work(i,a[i],a[i],1);
    }cout<<lst;
    return 0;
}
//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);
