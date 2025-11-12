#include <bits/stdc++.h>
using namespace std;
int n,m;
char c;
bool s[2010];
int la[514];
bool al1=1;
int mod=998244353,ans;
int ap[514];
bool us[514];
void sol(){
    int den=0;
    for(int i=1;i<=n;i++){
        if(s[i]==0||la[ap[i]]<=den){
            den++;
        }
    }
    if(n-den>=m){
        ans++;
        if(ans==mod)ans=0;
    }
    //cout<<den<<endl;
    return;
}
void goi(int pl){
    if(pl==n+1){
        sol();
        return;
    }
    for(int i=1;i<=n;i++){
        if(us[i]==0){
            us[i]=1;
            ap[pl]=i;
            goi(pl+1);
            us[i]=0;
        }
    }
}
int main(){

  freopen("employ.in","r",stdin);
   freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c;
        if(c=='1'){
            s[i]=1;
            if(s[i]==0)al1=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>la[i];
        if(la[i]==0)al1=0;
    }
    if(n==m){
        if(al1){
            ans=1;
            for(int i=1;i<=n;i++){
                ans*=i;
                ans%=mod;
            }
            cout<<ans<<endl;
        }else{
            cout<<0<<endl;
            return 0;
        }
    }
    goi(1);
    cout<<ans;
    return 0;
}
