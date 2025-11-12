#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
using namespace std;

int t;

ll a[100010][5];

struct T{
    int pos,j;
    T(){}
    T(int x,int jx):pos(x),j(jx){}
    friend bool operator < (T n,T m){
        int jx1,jx2;
        if(n.j==1){
            jx1=2;
            jx2=3;
        }
        else if(n.j==2){
            jx1=1;
            jx2=3;
        }
        else{
            jx1=1;
            jx2=2;
        }
        return (a[n.pos][n.j]-max(a[n.pos][jx1],a[n.pos][jx2]))>(a[m.pos][m.j]-max(a[m.pos][jx1],a[m.pos][jx2]));
    }
};

int n;

priority_queue<T> P[5];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int upline=n/2;
        for(int i=1;i<=n;++i)
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
        for(int i=1;i<=n;++i){
            int posj=0;
            a[i][0]=-1;
            for(int j=1;j<=3;++j)
                if(a[i][posj]<a[i][j]) posj=j;
            P[posj].push(T(i,posj));
            if(P[posj].size()>upline){
                T x=P[posj].top();
                P[posj].pop();
                x.j=0;
                for(int k=1;k<=3;++k){
                    if(k==posj) continue;
                    if(a[x.pos][x.j]<a[x.pos][k]) x.j=k;
                }
                P[x.j].push(x);
            }
        }
        ll ans=0;
        for(int i=1;i<=3;++i){
            while(!P[i].empty()){
                ans+=a[P[i].top().pos][i];
                P[i].pop();
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
