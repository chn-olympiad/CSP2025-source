#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n;
struct st{
    int u,v,w;
}a[N];
struct st1{
    int u,v,w;
    friend bool operator < (st1 a,st1 b){
        return a.u+max(b.v,b.w)>b.u+max(a.v,a.w);
    }
};
struct st2{
    int u,v,w;
    friend bool operator < (st2 a,st2 b){
        return a.v+max(b.u,b.w)>b.v+max(a.u,a.w);
    }
};
struct st3{
    int u,v,w;
    friend bool operator < (st3 a,st3 b){
        return a.w+max(b.v,b.u)>b.w+max(a.v,a.u);
    }
};
priority_queue<st1> q1;
priority_queue<st2> q2;
priority_queue<st3> q3;
void check(int x,int i){
    if(x==1){
       if(q1.size()==n/2){
            auto [u,v,w]=q1.top();
            q1.pop();
            if(u+max(a[i].v,a[i].w)<a[i].u+max(v,w)){
                q1.push({a[i].u,a[i].v,a[i].w});
                if(v>w) q2.push({u,v,w});
                else q3.push({u,v,w});
            }
            else{
            	q1.push({u,v,w});
                if(a[i].v>a[i].w) q2.push({0,a[i].v,a[i].w});
                else q3.push({0,a[i].v,a[i].w});
            }
        }
        else q1.push({a[i].u,a[i].v,a[i].w});
    }
    else if(x==2){
        if(q2.size()==n/2){
            auto [u,v,w]=q2.top();
            q2.pop();
            if(v+max(a[i].u,a[i].w)<a[i].v+max(u,w)){
                q2.push({a[i].u,a[i].v,a[i].w});
                if(u>w) q1.push({u,v,w});
                else q3.push({u,v,w});
            }
            else{
            	q2.push({u,v,w});
                if(a[i].u>a[i].w) q1.push({a[i].u,0,a[i].w});
                else q3.push({a[i].u,0,a[i].w});
            }
        }
        else q2.push({a[i].u,a[i].v,a[i].w});
    }
    else{
        if(q3.size()==n/2){
            auto [u,v,w]=q3.top();
            q3.pop();
            if(w+max(a[i].v,a[i].u)<a[i].w+max(v,u)){
                q3.push({a[i].u,a[i].v,a[i].w});
                if(v>=u) q2.push({u,v,w});
                else q1.push({u,v,w});
            }
            else{
            	q3.push({u,v,w});
                if(a[i].v>=a[i].u) q2.push({a[i].u,a[i].v,0});
                else q1.push({a[i].u,a[i].v,0});
            }
        }
        else q3.push({a[i].u,a[i].v,a[i].w});
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        while(!q3.empty()) q3.pop();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].u>>a[i].v>>a[i].w;
        }
        for(int i=1;i<=n;i++){
            if(a[i].u>=a[i].v&&a[i].u>=a[i].w){
                check(1,i);
            }
            else if(a[i].v>=a[i].u&&a[i].v>=a[i].w){
                check(2,i);
            }
            else{
                check(3,i);
            }
        }
        int ans=0;
        while(!q1.empty()){
            auto [u,v,w]=q1.top();
            q1.pop();
            ans+=u;
        }
        while(!q2.empty()){
            auto [u,v,w]=q2.top();
            q2.pop();
            ans+=v;
        }
        while(!q3.empty()){
            auto [u,v,w]=q3.top();
            q3.pop();
            ans+=w;
        }
        cout<<ans<<"\n";
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

1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522

1
4
7 8 9
7 8 9
7 8 9
9 8 7
CSP-S RP=LONG_LONG_MAX
*/
