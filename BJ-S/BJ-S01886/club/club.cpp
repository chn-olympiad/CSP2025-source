#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int S = 1e5+10;
int a1[S],a2[S],a3[S];
priority_queue<ll,vector<ll>,greater<ll> > q1,q2,q3;

inline int nmax(int a,int b,int c) {
    return max(max(a,b),c);
}

inline int s_max(int a,int b,int c){
    if(a > b) swap(a,b);
    if(b > c) swap(b,c);
    if(a > b) swap(a,b);
    return b;
}

inline void _delete(){
    while(!q1.empty()) q1.pop();
    while(!q2.empty()) q2.pop();
    while(!q3.empty()) q3.pop();
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        ll ans = 0;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++){
            scanf("%d %d %d",&a1[i],&a2[i],&a3[i]);
            int m = nmax(a1[i],a2[i],a3[i]),s = s_max(a1[i],a2[i],a3[i]);
            ans += m;
            if(m == a1[i]) q1.push(m-s);
            else if(m == a2[i]) q2.push(m-s);
            else if(m == a3[i]) q3.push(m-s);
        }
        while(q1.size() > n >> 1){
            ans -= q1.top();
            q1.pop();
        }while(q2.size() > n >> 1){
            ans -= q2.top();
            q2.pop();
        }while(q3.size() > n >> 1){
            ans -= q3.top();
            q3.pop();
        }
        printf("%lld\n",ans);
        _delete();
    }

    return 0;
}
