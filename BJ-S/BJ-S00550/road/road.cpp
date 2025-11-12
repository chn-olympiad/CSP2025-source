#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
//#include<pair>
#define MAXN 10010
using namespace std;
struct edge{
    int v;
    int w;
};
struct edgef{
    int u;
    int v;
    int w;
};
int tree[MAXN];
int n,m,k;
/*
int fnd(int p){

    if(tree[tree[p]]==tree[p])return tree[p];

    return tree[p] = fnd(tree[tree[p]]);
}
void add(int a,int b){
    if(tree[b]==b)
    tree[a] = fnd(b);

}
*/
int fnd(int p){

    if(tree[tree[p]]==tree[p])return tree[p];
    tree[p] = fnd(tree[tree[p]]);
    return tree[p];
}
void add(int a,int b){
    int tmpa = fnd(a);
    int tmpb = fnd(b);

    if(tree[tmpa]!=tree[tmpb])tree[tmpa] = tree[tmpb];

}
bool operator<(edgef a,edgef b){
    return a.w<b.w;
}
//vector<edge> lst;
priority_queue<pair<int,edgef>,vector<pair<int,edgef>>,greater<pair<int,edgef>>> let;
pair<int,edgef> makepair(int a,edgef b){
    pair<int,edgef> l;
    l.first = a;
    l.second = b;
    return l;
}
void print(){
        for(int i = 1;i<=6;i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
//    lst.resize(m+1+k+1);
    for(int i = 1;i<=n+k+1;i++){
        tree[i] = i;
    }
    int tmpu,tmpv,tmpw;
    for(int i = 1;i<=m;i++){
        cin>>tmpu>>tmpv>>tmpw;
        /*
        edge tmpe;
        tmpe.v = tmpv;
        tmpe.w = tmpw;
        lst[tmpu].push_back(tmpe);
        tmpe.v = tmpu;
        lst[tmpv].push_back(tmpe);
        */
        edgef tmpf;
        tmpf.u = tmpu;
        tmpf.v = tmpv;
        tmpf.w = tmpw;
        let.push(make_pair(tmpw,tmpf));
    }
    int tmpa;
    int pocnt = m+1;
    for(int i = 1;i<=k;i++){
        cin>>tmpa;
        for(int i = 1;i<=m;i++){
            cin>>tmpw;
            edgef h;
            h.u = pocnt;
            h.w = tmpw;
            h.v = i;

            let.push( make_pair(tmpw,h) );
        }
        pocnt++;
    }
    long long ans = 0;
    while(!let.empty()){
        edgef tp = let.top().second;
//        print();
        if(fnd(tp.u)!=fnd(tp.v)){
 //                       printf("%d--%d->%d\n",tp.u,tp.w,tp.v);
            add(tp.u,tp.v);
            ans+=tp.w;
        }
        let.pop();
    }
    printf("%lld" ,ans);
}
