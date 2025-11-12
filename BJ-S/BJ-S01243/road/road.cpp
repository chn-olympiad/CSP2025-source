#include<bits/stdc++.h>
using namespace std;
long long tne[14][10045],ne[14][10045],neww[19],o=0;
vector<vector<pair<long long,long long> > >b(10049);
vector<vector<pair<long long,long long> > >a(10049);
priority_queue<pair<long long,pair<long long,long long> >,vector<pair<long long,pair<long long,long long> >>,greater<pair<long long,pair<long long,long long> >> >pq;
bool c[10049];
void f(long long k){
    for(int i=0;i<b[k].size();i++){
        auto t=make_pair(b[k][i].second,make_pair(k,b[k][i].first));
        if(c[t.second.second]==0)
        pq.push(t);
    }
}
int main(){
    //

    freopen("road.in","r",stdin);
    //

    freopen("road.out","w",stdout);
    long long i,j,n,m,k,kt,u,v,w,T;
    cin>>n>>m>>k;
    for(i=0;i<m;i++){
        u=0,v=0,w=0;

        scanf("%d %d %d",&u,&v,&w);
        u--;v--;
        auto t=make_pair(v,w);
        b[u].push_back(t);
        t=make_pair(u,w);
        b[v].push_back(t);
    }
    for(i=0;i<k;i++){
        cin>>neww[i];;
        for(j=0;j<n;j++)scanf("%d",&ne[i][j]);
    }
    f(0);
    int sum=1;
    c[0]=1;
    long long sumy=0;
    while(sum<n){
        auto t=pq.top();
        pq.pop();
        while(c[t.second.second]==1){
            t=pq.top();
            pq.pop();
        }
        w=t.first;
        u=t.second.first;
        v=t.second.second;
        auto t1=make_pair(v,w);
        a[u].push_back(t1);
        t1=make_pair(u,w);
        a[v].push_back(t1);
        sumy+=w;
        c[t.second.second]=1;
        f(t.second.second);
        sum++;
    }kt=0;

    long long nt=n,mina=1E18;
    for(T=0;T<pow(2,k);T++){

        n=nt;
long long suma=0;
i=0;
        int ttt=T;
        while(ttt>0){
            if(ttt&1==1){
n++;
            }
            ttt>>=1;
            i++;
        }
        if(n-nt>5)continue;pq.emplace();
        n=nt;
        i=0;
        for(i=0;i<n;i++)b[i].clear();
        for(i=0;i<n;i++){
            for(j=0;j<a[i].size();j++){
                auto t=a[i][j];
                b[i].push_back(t);
            }
        }int tt=T;

        i=0;
        n=nt;
        while(tt>0){
            if(tt&1==1){
                for(j=0;j<nt;j++){
                    u=n,v=j,w=ne[i][j];
                    auto t=make_pair(v,w);
                    b[u].push_back(t);
                    t=make_pair(u,w);
                    b[v].push_back(t);
                }
                suma+=neww[i];n++;
            }
            tt>>=1;
            i++;
        }
    for(i=0;i<n;i++)c[i]=0;
    f(0);
    int sum=1;
    c[0]=1;
    while(sum<n){
        auto t=pq.top();
        pq.pop();
        while(c[t.second.second]==1){
            t=pq.top();
            pq.pop();
        }
        w=t.first;
        u=t.second.first;
        v=t.second.second;
        c[t.second.second]=1;
        f(t.second.second);
        sum++;
        suma+=w;
    }
    if(suma<mina)mina=suma;
    }cout<<mina;
}
