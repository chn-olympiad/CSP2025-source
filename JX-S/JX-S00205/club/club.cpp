#include <bits/stdc++.h>

#define rep(i,l,r) for(auto i(l);i<=r;++i)
#define per(i,l,r) for(auto i(r);i>=l;--i)

typedef long long LL;
typedef std::pair<int,int> PII;

const int N = 100010;
const int M = 2000010;
const auto INF = 0x3f3f3f3f;

inline LL read(){
    LL x=0;char ch=getchar();bool f=0;
    while(ch<'0' || ch>'9'){f=(ch=='-');ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f?-x:x;
}

int n;

struct node{
    int x,y,id;
    bool operator<(const node &a) const{return x<a.x;}
};

std::vector<PII> v[N];
std::priority_queue<node> q[3];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T=read();

    while(T--){
        n=read();

        rep(i,1,n){
            int x=read(),y=read(),z=read();
            v[i].clear();
            v[i].push_back({x,0});
            v[i].push_back({y,1});
            v[i].push_back({z,2});
            std::sort(v[i].begin(),v[i].end(),[](PII x,PII y){return x>y;});
        }

        LL sum=0;

        rep(i,1,n){
            if(q[v[i][0].second].size()<(n>>1)){
                sum+=v[i][0].first;
                q[v[i][0].second].push({v[i][1].first-v[i][0].first,0,i});
            }
            else{
                auto t=q[v[i][0].second].top();
                if(t.x+v[i][0].first>v[i][1].first){
                    sum+=t.x+v[i][0].first;q[v[i][0].second].pop();
                    q[v[i][0].second].push({v[i][1].first-v[i][0].first,0,i});
                    q[v[t.id][t.y^1].second].push({v[t.id][t.y].first-v[t.id][t.y^1].first,t.y^1,t.id});
                }
                else{
                    sum+=v[i][1].first;
                    q[v[i][1].second].push({v[i][0].first-v[i][1].first,1,i});
                }
            }
        }

        printf("%lld\n",sum);

        while(!q[0].empty()){q[0].pop();}
        while(!q[1].empty()){q[1].pop();}
        while(!q[2].empty()){q[2].pop();}
    }

    return 0;
}
/*
-O2 -Wall -static -o
-fsanitize=address,undefined -Wall -O2 -o
*/
