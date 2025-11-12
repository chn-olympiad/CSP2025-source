#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
const int N=505;
int a[N];
bool cmp(int a,int b){
    return a>b;
}
int mb,ans=0;
void dfs(int rt,int sum){
    if(rt>n) return;
    if(sum>mb) ans++;
    dfs(rt+1,sum+a[rt]);
    dfs(rt+1,sum);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(n<=3){
        if(a[1]+a[2]+a[3]>a[1]*2){
            cout<<1<<endl;
        }
        else cout<<0<<endl;
        return 0;
    }
    if(n<=20){
        int zans=0;
        for(int i=1;i<=n-3;i++){
            mb=a[i];
            dfs(i+1,0);
            zans+=ans;
            zans%=998244353;
        }
        cout<<zans<<endl;
    }
    else{
        ans=1;
        for(int i=1;i<=n-3;i++){
            ans=ans*2%998244353;
        }
        int ans1=n*(n-1)*(n-2)/6;
        cout<<ans*ans1%998244353;
    }
}
