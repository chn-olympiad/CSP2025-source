#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,cnt,now,dp[500005];
struct node{
    int num,id;
    bool operator < (node a) const{
        if(num==a.num) return id<a.id;
        return num<a.num;
    }
}a[500005],lb;
struct edge{
    int l,r;
    bool operator < (edge a) const{
        return r<a.r;
    }
}e[1000005];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        a[i].id=i;
        a[i].num^=a[i-1].num;
    }
    sort(a+1,a+1+n);
//    for(int i=0;i<=n;i++) cout<<a[i].num<<' ';
//    cout<<'\n';
    for(int i=0,tmp;i<=n;i++){
        lb=a[i];
        lb.num^=k;
        if(lb.num<a[i].num) continue;
        tmp=lower_bound(a+0,a+1+n,lb)-a;
//        cout<<tmp<<' ';
        if(tmp&&a[tmp-1].num==lb.num) e[++cnt].l=a[tmp-1].id+1,e[cnt].r=lb.id;
        if(tmp==i) tmp++;
        if(a[tmp].num==lb.num) e[++cnt].l=lb.id+1,e[cnt].r=a[tmp].id;
//        cout<<lb.id<<' '<<lb.num<<' '<<a[tmp].id<<' '<<a[tmp].num<<'\n';
    }
    sort(e+1,e+1+cnt);
//    for(int i=1;i<=cnt;i++) cout<<e[i].l<<' '<<e[i].r<<'\n';
    now=1;
    for(int i=1;i<=n;i++){
        while(e[now].r==i){
            dp[i]=max(dp[i],dp[e[now].l-1]+1);
            now++;
        }
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout<<dp[n];
    return 0;
}
