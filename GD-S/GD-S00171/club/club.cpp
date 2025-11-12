#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n;
struct node{
    ll w[10];
    int f,s,t;
}a[N];
bool cmp(node p,node q){
    // ll res1 = min({p.w[1], p.w[2], p.w[3]});
    // ll res2 = min({q.w[1], q.w[2], q.w[3]});
    // return res1 < res2;
    // int res = 0;
    // for(int i=1;i<=3;i++){
    //     if(p.w[i] < q.w[i]) res ++;
    // }
    // if(res >= 3) return 1;
    // else return 0;
    //ll res1 = p.w[p.f] - p.w[p.s];
    //ll res2 = q.w[q.f] - q.w[q.s];
    return p.w[p.f] - p.w[p.s] > q.w[q.f] - q.w[q.s];
    // if(res1 < res2) return false;
    // else return true;
}
int cnt[10];

void solve(int i){
    int f,s,t;
    if(a[i].w[1] >= a[i].w[2] && a[i].w[1] >= a[i].w[3]){
        f = 1;
        if(a[i].w[2] >= a[i].w[3]) s = 2, t = 3;
        else s = 3, t = 2;
    }
    else if(a[i].w[2] >= a[i].w[1] && a[i].w[2] >= a[i].w[3]){
        f = 2;
        if(a[i].w[1] >= a[i].w[3]) s = 1, t = 3;
        else s = 3, t = 1;
    }
    else{
        f = 3;
        if(a[i].w[1] >= a[i].w[2]) s = 1, t = 2;
        else s = 2, t = 1;
    }
    a[i].f = f; a[i].t = t; a[i].s = s;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].w[1]>>a[i].w[2]>>a[i].w[3];
            solve(i);
        }
        sort(a+1,a+1+n,cmp);
        
        ll ans = 0;
        for(int i=1;i<=n;i++){
            int f = a[i].f, s = a[i].s, t = a[i].t;
            if(cnt[f] < n / 2){
                cnt[f] ++;
                ans += a[i].w[f];
            }
            else if(cnt[s] < n / 2){
                cnt[s] ++;
                ans += a[i].w[s];
            }
            else{
                cnt[t] ++;
                ans += a[i].w[t];
            }
            //cout<<i<<": "<<a[i].w[1]<<" "<<a[i].w[2]<<" "<<a[i].w[3]<<"\n";
            //cout<<i<<": "<<f<<" "<<s<<" "<<t<<"\n";
        }
        cout<<ans<<"\n";
        memset(cnt,0,sizeof(cnt));
    }
    

    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
