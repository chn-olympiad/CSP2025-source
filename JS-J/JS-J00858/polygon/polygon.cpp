#include<bits/stdc++.h>
using namespace std;
struct T{
    int id,x;
};
const int mod=998244353;
int n,a[5009],ans=0;
T lazy[10009];
int f[10009],len;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    f[0]=1;
    for(int j=1;j<=n;j++){
        for(int i=a[j]+1;i<=10001;i++){
            ans+=f[i];
            ans%=mod;
        }
        len=0;
        for(int i=0;i<=10001;i++){
            if(f[i])lazy[++len]={min(10001,i+a[j]),f[i]};
        }
        for(int i=1;i<=len;i++){
            f[lazy[i].id]+=lazy[i].x;
            f[lazy[i].id]%=mod;
        }
    }
    cout<<ans;
    return 0;
}
