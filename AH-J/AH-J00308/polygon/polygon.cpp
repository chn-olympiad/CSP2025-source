#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,v[1000001],t[10001],ans;
bool pd (){
    ll cnt=0,maxi=0;
    for(int i=1;i<=n;i++){
        if(t[i])cnt+=v[i],maxi=max(maxi,v[i]);
    }
    return cnt>maxi*2;
}

void check(int x,int s,int jb){
    if(s==x){
        if(pd()){
            ans++;
        }
        return;
    }

    for(int i=jb+1;i<=n;i++){


            t[i]=1;
            check(x,s+1,i);
            t[i]=0;

    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];
    sort(v+1,v+n+1);
    for(int i=3;i<=n;i++){
        memset(t,0,sizeof(t));
        check(i,0,0);
    }
    cout<<ans%998244353;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
