#include<bits/stdc++.h>
using namespace std;
int n,m,k,fe[100001];

struct ky{
    int s,e,f;
}a[10001];

struct ks{
    int st,en;
}b[100001];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 0;i<m;i++){
        cin>>a[i].s>>a[i].e>>a[i].f;
    }
    for(int i = 0;i<k;i++){
        for(int j = 0;j<n;j++){
            cin>>b[i].st>>b[i].en>>;
        }
    }

}
