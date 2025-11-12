#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct nn{
    int a,i;
    bool operator<(nn o){
        return a>o.a;
    }
};

int li[5],lim;

struct node{
    int ai[5],x[5],id[5];
    void set_(int a,int b,int c){
        nn t[3]={{a,1},{b,2},{c,3}};
        sort(t,t+3);
        ai[1]=a,ai[2]=b,ai[3]=c;
        x[1]=t[0].a,x[2]=t[1].a,x[3]=t[2].a;
        id[1]=t[0].i,id[2]=t[1].i,id[3]=t[2].i;
    }
    int get(int n){
        for(int i=1;i<=3;i++){
            if(li[id[i]]<lim) {
                n--;
                if(n==0) return id[i];
            }
        }
        return -1;
    }
    bool operator<(node o){
        return ai[get(1)]-ai[get(2)] > o.ai[o.get(1)]-o.ai[o.get(2)];
    }
} p[100005];

void solve(){
    memset(li,0,sizeof li);
    int n;cin>>n;
    lim=n/2;
    for(int i=1;i<=n;i++) {
        int a,b,c;cin>>a>>b>>c;
        p[i].set_(a,b,c);
    }
    sort(p+1,p+n+1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        int id=p[i].get(1);
        li[id]++;
        ans+=p[i].ai[id];
        if(li[id]==lim) sort(p+i+1,p+n+1);
    }
    cout<<ans<<"\n";
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--) solve();
    return 0;
}
