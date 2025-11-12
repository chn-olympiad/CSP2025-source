#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[505],x[505];
int m,n;
int z[505],xu[505];
const int MOD=998244353;
void init(){
    memset(s,0,sizeof(s));
    memset(x,0,sizeof(x));
    memset(z,0,sizeof(z));
}
int jiec(int a){
    int ans=1;
    for(int i=1;i<=a;i++){
        ans*=i;
        ans%=MOD;
    }
    return ans;
}
int yw[505];
int xl[505];
int tong[505];
bool pd(){
    for(int i=1;i<=m;i++){
        tong[xl[i]]++;
        if(tong[xl[i]]>=2){
            return false;
        }
    }
    return true;
}
int sh(){
    int lans=0;
    for(int i=1;i<=m;i++){
        if(x[i]>=s[xl[i]]){
            lans++;
        }
        else{
            continue;
        }
    }
    return lans;
}
int zzans;
void dfs(){
    if(xl[0]>0){
        return;
    }
    xl[m]++;
    for(int i=m;i>=1;i--){
        if(xl[i]>m){
            xl[i]-=m;
            xl[i-1]++;
        }
        else{
            break;
        }
    }
    int flag=pd();
    if(flag==true){
        if(sh()>n){
            zzans++;
        }
    }
    else{
        dfs();
    }
    return;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    init();
    cin>>m>>n;
    char c;
    int ys=0;
    for(int i=1;i<=m;i++){
        cin>>c;
        if(c=='1'){
            s[i]=s[i-1];
            ys++;
            yw[ys]=i;
        }
        else{
            s[i]=s[i-1]+1;
        }
    }
   // for(int i=1;i<=m;i++){
    //    cout<<s[i]<<" ";
   // }
  //  cout<<endl;
    for(int i=1;i<=m;i++){
        cin>>x[i];
        z[i]=m;
    }
    sort(x+1,x+1+m);
    int ls=1;
    for(int i=1;i<=m;i++){
        for(int j=ls;j<=m;j++){
            if(x[i]<=s[j]){
                z[i]=j-1;
                ls=j;
                break;
            }
        }
    }
  //  for(int i=1;i<=m;i++){
  //      cout<<z[i]<<" ";
  //  }

   // cout<<endl;
    for(int i=m;i>=1;i--){
        if(s[i]==s[i-1]||(i==1&&s[i]==0)){
            for(int j=1;j<=m;j++){
                if(z[j]>=i){
                    xu[i]++;
                }
            }
        }
        else{
            xu[i]=0;
        }
    }
  //  for(int i=1;i<=m;i++){
 //       cout<<xu[i]<<" ";
  //  }
  //  cout<<endl;
    int ans=0,zs=0,cs=1,js=0;
    for(int i=ys;i>=n;i--){
        if(n==ys){
            cs=1;
            for(int j=m;j>=1;j--){
                if(xu[j]>0){
                    if(xu[j]-zs<=0){
                        cs=0;
                        break;
                    }
                    cs*=(xu[j]-zs);
                    cs%=MOD;
                    zs++;
                    js=j;
                }
                if(zs>=i){
                    break;
                }
            }
            ans+=cs;
            ans%=MOD;
            int jc=m-i;
            ans*=jiec(jc);
            ans%=MOD;
        }
        else if(ys==m){
            ans*=jiec(ys);
        }
        else{
            for(int j=1;j<=n;j++){
                xl[j]=j;
            }
            xl[n+1]=0;
            dfs();
            ans=zzans;
        }
    }
    cout<<ans<<endl;
    return 0;
}
