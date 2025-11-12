#include<bits/stdc++.h>
using namespace  std;
int n,m,k;
struct rd{
    int a;
    int b;
    int costs;
};
vector<rd>roads;
struct tow{
    int c;
    int s[10001];
    int sum;
};
vector<tow>towns;
bool comp(tow a,tow b){
    return a.sum<b.sum;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        rd r;
        cin>>r.a>>r.b>>r.costs;
        roads.push_back(r);
    }
    for(int i=1;i<=k;i++){
        tow t;
        cin>>t.c;
        for(int j=1;j<=n;j++){
            cin>>t.s[i];
            t.sum+=t.s[i];
        }
    }
    sort(towns.begin(),towns.end(),comp);
    cout<<towns[1].sum;
    return 0;
}