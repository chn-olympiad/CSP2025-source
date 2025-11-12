#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5001],ans=0,n;
int C(int q,int w){
    double res=1;
    for(int i=0;i<w;i++){
        res=res*(q-i)/(i+1);
    }
    return int(res);
}
void poolr(int num){
    for(int i=3;i<=num;i++){
        ans=(ans+C(num,i))%MOD;
    }
    cout<<ans<<endl;
    exit(0);
}
void dfs(int num,int mx,int sm,int muc,bool f){
    if(num>n) return ;
    if(sm>mx*2&&f==1&&muc>=3){
        ans=(ans+1)%MOD;
    }
    dfs(num+1,mx,sm,muc,0);
    dfs(num+1,a[num+1],sm+a[num+1],muc+1,1);
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    int maxnnnn=-1,summ=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxnnnn=max(maxnnnn,a[i]);
        if(a[i]==1) summ++;
    }
    if(maxnnnn==1) poolr(summ);
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3]){
            cout<<1<<endl;
            return 0;
        }
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        dfs(i,a[i],a[i],1,1);
    }

    cout<<ans<<endl;
    return 0;
}
