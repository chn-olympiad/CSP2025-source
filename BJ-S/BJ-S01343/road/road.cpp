#include<bits/stdc++.h>
using namespace std;
#define long long int
int n,m,k,uu,vv,ww,anss;


struct c1{
    int c,ok;
    vector<int>e;
}ch[100];
vector<int>ee;
int dfs1(int m,int cc,vector<int>h,int ans){
    if(ch[m-1].ok==1){
        for(int q:ch[m-1].e){
            h.push_back(q);
        }
        ans+=ch[m-1].c;

    }
    if(m>k){
        sort(h.begin(),h.end());
        for(int i=0;i<n+cc-1;i++){
            ans+=h[i];

        }
        anss=min(ans,anss);
        return 0;
    }
    ch[m].ok=0;
    dfs1(m+1,cc,h,ans);
    ch[m].ok=1;
    dfs1(m+1,cc+1,h,ans);

    return 0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    anss=100000000;
    for(int i=1;i<=m;i++){
        cin>>uu>>vv>>ww;
        ee.push_back(ww);
    }
    for(int i=1;i<=k;i++){
        cin>>ch[i].c;
        for(int j=1;j<=n;j++){
            cin>>ww;
            ch[i].e.push_back(ww);
        }
    }
    dfs1(1,0,ee,0);
    cout<<anss;
    return 0;
}
