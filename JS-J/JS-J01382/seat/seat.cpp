#include <bits/stdc++.h>
using namespace std;
int a[15*15],b[15][15];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,tgt_score;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            tgt_score=a[i];
        }
    }
    sort(a+1,a+1+n*m,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                cnt++;
                b[j][i]=a[cnt];
            }
        }else{
            for(int j=n;j>=1;j--){
                cnt++;
                b[j][i]=a[cnt];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==tgt_score){
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
