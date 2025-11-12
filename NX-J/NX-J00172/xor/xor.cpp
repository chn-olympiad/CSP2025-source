#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,k,a[N],s[N],ans[N],cnt,cn,c;
struct node{
    ll x,y;
};
node vis[N];
bool if1(ll ax ,ll ay){
    ll b=0;
    for(int i=1;i<=c;i++){
        if(vis[i].x>ay||ax>vis[i].y){
            b++;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1] xor a[i] ;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans[++cnt]=abs(s[j]-s[i-1]);
        }
    }
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(ans[++cnt]==k && if1(i,j)){
                vis[++c].x=i;
                vis[++c].y=j;
                cn++;

            }
        }

    }
    cout<<cn;
    return 0;
}
