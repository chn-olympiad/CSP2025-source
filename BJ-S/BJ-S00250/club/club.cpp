#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define random 1ll*rand()*rand()+1ll*rand()*rand();
#define ioos ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef __int128 i128;
typedef unsigned __int128 u128;
struct node{
    int a,b,c;
    int cost;
    friend bool operator<(const node &a,const node &b){
        return a.cost>b.cost;
    }
};
priority_queue<node> la,lb,lc;
int main(){
    ioos;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(a==max(a,max(b,c)))
                la.push({a,b,c,a-max(b,c)});
            else if(b==max(a,max(b,c)))
                lb.push({a,b,c,b-max(a,c)});
            else if(c==max(a,max(b,c)))
                lc.push({a,b,c,c-max(a,b)});
        }
        int ans=0;
        while(la.size()>n/2)
            ans+=la.top().a-la.top().cost,la.pop();
        while(lb.size()>n/2)
            ans+=lb.top().b-lb.top().cost,lb.pop();
        while(lc.size()>n/2)
            ans+=lc.top().c-lc.top().cost,lc.pop();
        //cout<<ans<<'\n';
        while(la.size())
            ans+=la.top().a,la.pop();
        while(lb.size())
            ans+=lb.top().b,lb.pop();
        while(lc.size())
            ans+=lc.top().c,lc.pop();
        cout<<ans<<'\n';
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
