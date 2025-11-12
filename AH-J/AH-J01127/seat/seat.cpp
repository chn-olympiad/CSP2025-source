#include<bits/stdc++.h>
using namespace std;
struct node{
    int xh;
    int cj;
}cjb[110];
bool cmp(node x,node y){
    return x.cj>y.cj;
}
int n,m,mp[20][20];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cjb[i].xh=i;
        cin>>cjb[i].cj;
    }
    sort(cjb,cjb+n*m,cmp);
    int bj=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            mp[j][i]=cjb[bj].xh;
            bj++;
        }
        i++;
        for(int j=n-1;j>=0;j--){
            mp[j][i]=cjb[bj].xh;
            bj++;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mp[i][j]==0){
                cout<<j+1<<" "<<i+1;
            }
        }
    }
    return 0;
}
