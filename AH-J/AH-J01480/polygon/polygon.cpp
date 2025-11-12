#include<bits/stdc++.h>
using namespace std;
int n,a[10005],maxn;
const int mod=998244353;
int cnt;
//64 points
void dfs(int cur,int tgt,int ccnt,int suma,int maxa){
    //cerr<<tgt<<' '<<cur<<endl;
    if(ccnt+n-cur+1<tgt) return;
    if(cur==n){
        if(ccnt==tgt){
            cnt=(cnt+(suma>2*maxa?1:0))%mod;
            //cerr<<'A'<<suma<<' '<<maxa<<endl;
        }
        return;
    }
    dfs(cur+1,tgt,ccnt+1,suma+a[cur+1],max(a[cur+1],maxa));
    dfs(cur+1,tgt,ccnt,suma,maxa);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1){//24 points
        int sum=0,x=1,y=1;
        for(int i=1;i<=n;++i){
            x=x*(n-i+1)%mod;
            y=y*i%mod;
            if(i>=3) sum=(sum+x/y)%mod;
        }
        cout<<sum;
    }else{//40 points
        for(int i=3;i<=n;++i){
            dfs(0,i,0,0,0);
        }
        cout<<cnt;
    }
    return 0;
}
