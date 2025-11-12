#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
const ll p=998244353;
int n;
ll ans;
int a[5005];
ll pw[5005];
bool flag;
void dfs(int maxn,int dep,ll sum){
    if (dep==n){
        if (sum>2*maxn) ans=(ans+1)%p;
        return;
    }
    dfs(max(maxn,a[dep+1]),dep+1,sum+a[dep+1]);
    dfs(maxn,dep+1,sum);
}
ll q_pow(int a,int b){
    ll res=1,x=a%p;
    while (b){
        if (b&1) res=res*x%p;
        x=x*x%p;
        b>>=1;
    }
    return res;
}

int main (){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    flag=true;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (a[i]!=1) flag=false;
    }
    pw[0]=1;
    for (int i=1;i<=n;i++){
        pw[i]=pw[i-1]*i;
    }
    if (flag){
        for (int i=3;i<=n;i++){
            ans=(ans+(pw[n]*q_pow(pw[n-i],p-2)%p)*q_pow(pw[i],p-2)%p)%p;
        }
        cout << ans << endl;
        return 0;
    }
    dfs(0,0,0);
    cout << ans << endl;
    return 0;
}
//rp++
//qiuqiulerangwo300+