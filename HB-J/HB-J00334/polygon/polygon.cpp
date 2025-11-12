#include<bits/stdc++.h>
#define int long long
const int MOD=998244353;
using namespace std;
int n,a[5005];
int book[5005];
int li;
int clt;
void dfs(int step,int cir){
    if(step==li-1){
        book[cir]=1;
        int cnt=0,ckt=0;
        for(int i=1;i<=n;i++){
            if(book[i]==1){
                cnt+=a[i];
                ckt=max(ckt,a[i]);
            }
        }
        book[cir]=0;
        if(cnt>2*ckt) clt++;
        return;
    }
    book[cir]=1;
    for(int i=cir+1;i<=n;i++){
        dfs(step+1,i);
    }
    book[cir]=0;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        for(int i=1;i<=n-2;i++){
            for(li=3;li<=20;li++){
                dfs(0,i);
            }
        }
        cout<<clt%MOD<<endl;
    }else{
        int kkk=1;
        for(int i=1;i<=n;i++){
            kkk*=2;
            kkk%=MOD;
        }
        kkk+=MOD;
        kkk--;
        kkk-=n;
        kkk-=n*(n-1)/2;
        cout<<kkk%MOD<<endl;
    }
    return 0;
}
