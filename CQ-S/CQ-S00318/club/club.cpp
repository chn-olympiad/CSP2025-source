#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
struct node{
    ll a,b,c;
    int ida,idb,idc;
}a[maxn];
bool cmp(node x,node y){
	ll tmp1=x.a-x.b,tmp2=y.a-y.b;
	ll tmp3=x.b-x.c,tmp4=y.b-y.c;
    if(tmp1!=tmp2) return tmp1>tmp2;
    if(tmp3!=tmp4) return tmp3>tmp4;
    if(x.a!=y.a) return x.a>y.a;
    if(x.b!=y.b) return x.b>y.b;
    return x.c>y.c;
}
int t,n,vis[4];
ll ans;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].ida=1,a[i].idb=2,a[i].idc=3;
            ll tmp=max(a[i].a,max(a[i].b,a[i].c));
            if(tmp==a[i].b){
                swap(a[i].a,a[i].b);
                swap(a[i].ida,a[i].idb);
            }else if(tmp==a[i].c){
                swap(a[i].a,a[i].c);
                swap(a[i].ida,a[i].idc);
            }
            if(a[i].b<a[i].c){
                swap(a[i].b,a[i].c);
                swap(a[i].idb,a[i].idc);
            }
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(vis[a[i].ida]==n/2){
                ans+=a[i].b;
                vis[a[i].idb]++;
            }else{
                ans+=a[i].a;
                vis[a[i].ida]++;
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=3;i++) vis[i]=0;ans=0ll;
    }
    return 0;
}
/*
1
30
6090 4971 4101
14495 19657 10011
6294 14948 17496
3266 18897 6963
3129 14412 12639
5331 7102 7590
12533 15635 16270
2339 16892 11211
6980 3113 19980
16859 13322 9404
16742 1573 8946
1285 5253 2697
18072 16412 5595
15870 17311 7711
19194 4644 11192
1306 6558 10317
11128 16814 5947
1603 6202 15251
4014 5797 2498
1557 4235 12431
1561 16149 16433
9399 1760 809
13383 18379 10169
7679 4131 17310
2900 8148 13627
14783 19510 17642
19717 4666 6335
9868 5451 19561
11196 1774 11436
10753 10148 6994
*/