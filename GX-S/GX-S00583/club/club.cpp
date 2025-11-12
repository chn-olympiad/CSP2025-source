#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int t,n,a[4];
struct st{
    ll val[4],p[4];
}tt[20005];
struct nd{
    ll val,id;
}p[4];
ll ans;
bool cmp1(nd u,nd v){
    return u.val > v.val;
}
bool cmp(st c,st b){
    if (c.val[1] != b.val[1]) return c.val[1] > b.val[1];
    else if (c.val[2] != b.val[2]) return c.val[2] > b.val[2];
    else return c.val[3] > b.val[3];
}
int main(){
    freopen("club1.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n;
        ll sum = 0;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=3;j++){
                cin>>a[j];
                p[j].val = a[j],p[j].id = j;
            }
            sort(p+1,p+4,cmp1);
            for (int j=1;j<=3;j++){
                tt[i].val[j] = p[j].val;
                tt[i].p[j] = p[j].id;
            }
        }
        int upval = n/2;
        sort(tt+1,tt+n+1,cmp);
        int k[4]={0,0,0,0};
        for (int i=1;i<=n;i++){
            if (k[tt[i].p[1]] <= upval) {
                    sum += tt[i].val[1];
                    k[tt[i].p[1]]++;
            }
            else sum += tt[i].val[2],k[tt[i].p[2]]++;
        }
        cout<<sum<<"\n";
        memset(tt,0,sizeof(tt));
    }
    //fflush(stdout);
    return 0;
}
