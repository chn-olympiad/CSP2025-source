#include "bits/stdc++.h"
using namespace std;
const int N=5e5 + 10;
int a[N],n,k,sum[N];
int d[N];
map<int,int> t;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=(a[i-1]^a[i]);
        sum[i]=(sum[i-1]^a[i]);
        t[d[i]]++;
    }
    for(int i=1;i<=n;i++){
        cout<<d[i]<<' ';
    }
    if(k!=0){
        int maxn=0;
        for(int i=1;i<=n;i++){
            //cout<<d[i]<<" ";
            int q=d[i]+k;
            if(t[q]){
                maxn=max(maxn,t[q]);
            }
            if(t[d[i]])maxn=max(maxn,t[d[i]]);
        }
        cout<<maxn;
    }else{
        int maxn=0;
        for(int i=1;i<=n;i++){
            //cout<<d[i]<<" ";
            int q=d[i]+k;
            if(t[q]){
                maxn=max(maxn,t[q]-1);
            }
            if(t[d[i]])maxn=max(maxn,t[d[i]]-1);
        }
        cout<<maxn;
    }
    return 0;
}
/*
0 2 3
2 1 0 3
2 3 3 0
2 3 1 3
*/
/*


4 3
2 1 0 3
2 -1 -1 3
4 2
2 1 0 3
2 -1 -1 3
4 0
2 1 0 3
2 -1 -1 3
*/
