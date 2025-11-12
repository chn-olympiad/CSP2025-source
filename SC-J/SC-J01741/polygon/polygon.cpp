#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=6000;
int n;
int a[MAXN],maxn=-1;
int ans,qaq;
void dfs(int x,int num,int sun,int zuid,int z){
    if(num>zuid*2&&sun>=3&&z==1){
        ans++;
        ans%=998244353;
        //cout<<x<<" "<<num<<" "<<sun<<" "<<zuid<<endl;
    }
    if(x==n){
        return;
    }
    for(int i=x+1;i<=n;i++){
        dfs(i,num+a[i],sun+1,max(zuid,a[i]),1);
    }
    return ;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(n<=2){
        cout<<0;
        return 0;
    }else if(n==3){
        if(a[1]+a[2]+a[3]>maxn){
            cout<<1;
            return 0;
        }
    }
    if(maxn==1){
        for(int i=3;i<=n;i++){
            qaq=1;
            for(int j=n;j>=n-3;j--){
                qaq*=n;
                qaq=qaq%998244353;
            }
            ans+=qaq;
            ans=ans%998244353;
        }
        cout<<ans;
        return 0;
    }
    dfs(0,0,0,0,0);
    cout<<ans;
    return 0;
}
//64
//100+100+65+64=329
//所以CCF有迷惑行为合集吗？