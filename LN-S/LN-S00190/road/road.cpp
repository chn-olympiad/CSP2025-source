#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,fa[10100],cnt,c[11],kp[11][10100];
void init(){
    for(int i = 1 ; i<= n ;i++){
        fa[i]=i;
    }
}
int ge(int op){
    if(fa[op]==op){
        return op;
    }
    return fa[op]=ge(fa[op]);
}

void merg(int x,int y){
    fa[ge(x)]=fa[ge(y)];
}

struct node{
    int u,v,w;
    bool operator < (const node &x) const{
        return x.w < w;
    }
};
priority_queue <node> lyq;
void goutu(){
    cnt=0;
    init();
    while(!lyq.empty()){
        node now=lyq.top();
        lyq.pop();
        if(fa[now.u] ==fa[now.v]){
            continue;
        }
        else{
            merg(now.u,now.v);
            cnt+=now.w;
        }
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >>m>>k;
    for(int i = 1 ;i <= m ;i++){
        int u_,v_,w_;
        scanf("%lld %lld %lld",&u_,&v_,&w_);
        lyq.push({u_,v_,w_});
    }
    goutu();
    cout <<cnt;
    return 0;
}
