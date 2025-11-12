#include<bits/stdc++.h>
using namespace std;

struct FST{
    long long n;
    long long F,S,T;
};

struct so{
    FST a,b,c;
};

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin >> t;
    while(t>0){
        long long n;
        cin >> n;
        so eo[n];
        for(long long i=0;i<n;i++){
            scanf("%lld%lld%lld",&eo[i].a.n,&eo[i].b.n,&eo[i].c.n);
            for(long long j=i;j>0&&eo[j-1].a.n<eo[j].a.n;j--){
                swap(eo[j-1].a.n,eo[j].a.n);
                swap(eo[j-1].b.n,eo[j].b.n);
                swap(eo[j-1].c.n,eo[j].c.n);
            }
            //printf("%lld %lld %lld\n",eo[i].a,eo[i].b,eo[i].c);
        }
        for(long long i=0;i<n;i++){
            printf("%lld %lld %lld\n",eo[i].a.n,eo[i].b.n,eo[i].c.n);
        }
        eo[0].a.F=1;
        eo[0].b.S=1;
        eo[0].c.T=1;
        for(long long i=1;i<n;i++){

        }
        cout << max(max(eo[0].a.n,eo[0].b.n),eo[0].c.n) << endl;
        t--;
    }

    return 0;
}
