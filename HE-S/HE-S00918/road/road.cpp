#include<bits/stdc++.h>
using namespace::std;
const int N=1e4+10;
const int M=1e6+10;
int n,m,k,a,cnt,cost=INT_MAX;
int city[N],rode1[M],rode2[M],rode3[M],cs[15],cs1[15],cs2[15],cs3[15],cs4[15];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        city[n]=n;
        cnt+=n;
    }
    for(int i=1;i<=m;i++){
        cin>>rode1[m]>>rode2[m]>>rode3[m];
    }
    for(int i=1;i<=k;i++){
        cin>>cs[k]>>cs1[k]>>cs2[k]>>cs3[k]>>cs4[k];
    }
    for(int i=0;i<m;i++){
        if(rode1[i]+rode2[i]+rode1[i+a]+rode2[i+a]==cnt){
            cost=min(rode3[i],cost);
        }
        a++;
    }
    cout<<cost;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
