#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,cnt=0;
LL a[10000+10];
LL qwe(LL cur,LL maxn,LL sum,LL c){
    if(cur==n&&c>=3){
        if(maxn<sum)return 1;
        else return 0;
    }
    LL cnt=0;
    for(int i=cur;i<n;i++){
        cnt=(cnt+qwe(i+1,max(maxn,a[i]),sum+a[i],c+1))%998244353;
    }
    return cnt;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3])cout<<1;
        else cout<<0;
    }else cout<<qwe(1,0,0,0);
    return 0;
}
