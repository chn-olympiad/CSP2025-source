#include<bits/stdc++.h>
using namespace std;
long long a[20][20],n,m,c[404],t;
bool cmp(int o,int p){
    return o>=p;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int l=n*m;
    for(int i=1;i<=l;i++){
        cin>>c[i];
    }
    t=c[1];
    sort(c+1,c+1+l,cmp);
    bool bj=1;
    int x=1,y=1,cnt=1;
    while(cnt<l){
        if(bj){
            for(int i=1;i<=n;i++){
                a[i][y]=c[cnt];
                x=i;
                cnt++;
            }
            if(y<m) y++;
            bj=0;
        }
        else{
           for(int i=n;i>=1;i--){
                a[i][y]=c[cnt];
                cnt++;
            }
            if(y<m) y++;
            bj=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==t){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
    return 0;
}
