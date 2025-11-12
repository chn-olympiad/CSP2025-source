#include<bits/stdc++.h>
using namespace std;
int sc[110];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    int cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>sc[i];
    }k=sc[1];
    sort(sc+1,sc+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt++;
            if(sc[cnt]==k){
                if(i&1)cout<<j;
                else cout<<m-j+1;
                cout<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
