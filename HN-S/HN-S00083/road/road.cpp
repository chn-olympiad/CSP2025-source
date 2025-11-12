#include<bits/stdc++.h>
using namespace std;
const int maxx=1e5+5;
map <int ,int> mp[maxx];
map <int ,int> mii[maxx];
struct B{
    int ct[10000],build;
}cs[100];
int n,m,k;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int city1,city2;
        cin>>city1>>city2;
        cin>>mp[city1][city2];
    }
    for(int i=1;i<=k;i++){
        cin>>cs[i].build;
        for(int j=1;j<=n;j++){
            cin>>cs[i].ct[j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int mi=INT_MAX;
            if(mp[i][j]){
                mi=mp[i][j];
            }else {
                for(int kk=1;kk<=k;kk++){
                    mi=min(mi,cs[kk].ct[i]+cs[kk].ct[j]+cs[kk].build);
                }
            }
            mii[i][j]=mii[j][i]=mi;
        }
    }
    int sumw=0,pos=1;
    map <int,int> mpp;
    mpp[0]=1;
        for(int i=1;i<n;i++){
            int jl=999999,www=0;
        for(int j=1;j<=n;j++){
            if(pos!=j&&!mpp[j]){
                if(jl>mii[pos][j]){
                    jl=mii[pos][j];
                    www=j;
                }
            }
        }
        ///cout<<pos<<" "<<www<<endl;
        sumw+=mii[pos][www];
        mii[pos][www]=mii[www][pos]=INT_MAX;
        mpp[pos]=1;
        pos=www;
    }
    cout<<sumw;
    return 0;
}
