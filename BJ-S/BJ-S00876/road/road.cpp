#include<bits/stdc++.h>
using namespace std;
struct road{
    int s,e,d;
    bool vis;
}r[110001];
bool empty(vector<bool> &b){
    for(int i=0;i<b.size();i++){
        if(b[i])return false;
    }
    return true;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>r[i].s>>r[i].e>>r[i].d;
    }
    vector<int> c(n+k,0);
    vector<bool> visc(m,false);
    for(int i=0;i<k;i++){
        r[m].s=m+1;
        r[m].e=i+1;
        cin>>c[n++]>>r[m++].d;
    }
    int cur=c[0],curp=1,minp=0;
    while(!empty(visc)){
        for(int i=0;i<m;i++){
            if((r[i].s==curp || r[i].e==curp) && !r[i].vis){
                if(r[i].d<r[minp].d)minp=i;
            }
        }
        cur+=r[minp].d;
        curp=(r[minp].s==curp?r[minp].e:r[minp].s);
        cur+=c[curp-1];
    }
    cout<<cur<<'\n';
    return 0;
}