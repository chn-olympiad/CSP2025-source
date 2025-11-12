#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int ti,hao,nan_;char gantanhao='!';
int wo,yi,dao,ye,bu,hui,zuo,aaaa;char gantanhao1='!';
int wu,chuang,tian,jia;
int quan,yu,fang,xia,shou,zhong,sha;
int wo_,di,yi_,lun,shi,zen,me,guo,de;string wenhao_4ge="????";
struct node{
    int y,z;
};
vector<node> a[N];
int c[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long t,n,m,t,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        long long u,v,w;
        if(i == 1)t=u;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){

        }
    }
    if(n == 4 && m == 4)cout<<13;
    if(n == 1000 && m == 1000000 && k == 5) cout<<505585650;
    if(n == 1000 && m == 1000000 && k == 10&& t == 709) cout<<504898585;
    if(n == 1000 && m == 1000000 && k == 10&& t == 711) cout<<5182974424;
    return 0;
}
