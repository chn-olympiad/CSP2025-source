# include <bits/stdc++.h>
using namespace std;
int n,a[5010],v[10000],ans;
void dfs(int deep,int d){
    if(deep>3){
        int sum=0,mx=0;
        for(int i=1; i<deep; i++) mx=max(mx,v[i]),sum+=v[i];
        if(sum>mx*2) ans++;
    }
    for(int i=d+1; i<=n; i++){
        v[deep]=a[i];
        dfs(deep+1,i);
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int bz=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]!=1){bz=1;break;}
    }
    if(bz==0){
        long long ans=0;
        for(int i=3; i<=n; i++){
            long long sum=1,x=n;
            for(int j=1; j<=i; j++){sum*=x;x--;sum%=998244353;}
            ans=(ans+sum/6)%998244353;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    dfs(1,0);
    cout<<ans;
    return 0;
}

/*
# include <bits/stdc++.h>
using namespace std;
int n,a[5010],v[10000],ans;
void dfs(int deep,int d){
    if(deep>3){
        int sum=0,mx=0;
        for(int i=1; i<deep; i++) mx=max(mx,v[i]),sum+=v[i];
        if(sum>mx*2) ans++;
    }
    for(int i=d+1; i<=n; i++){
        v[deep]=a[i];
        dfs(deep+1,i);
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    dfs(1,0);
    cout<<ans;
    return 0;
}
*/
