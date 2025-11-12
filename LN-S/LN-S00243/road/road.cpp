#include<bits/stdc++.h>
using namespace std;
unsigned int n,m,k,u,v,w,lenr[100005];
struct road{
    int to;
    int wealth;
}r;

bool cmp(road a,road b){
    return a,wealth>b.wealth;
}

road rs[100005][1005];//start/end;
int main(){
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)[
        cin >> u >> v >> r.wealth;
        r.to=v;
        rs[u][lenr[u]]=r;
        r.to=u;
        rs[v][lenr[v]]=r;
    ]
    sort(rs+1,rs+n+1,cmp);
    for(int )
}
