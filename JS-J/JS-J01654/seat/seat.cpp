#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[105];
bool cmp(int a,int b){
    return a>b;
}
ll b[15][15];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    int fff=n*m;
    for(int i=1;i<=fff;i++){
        cin>>a[i];
    }
    int ttt=a[1];
    sort(a+1,a+fff+1,cmp);
    int cnt=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                b[j][i]=a[cnt];
                cnt++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                b[j][i]=a[cnt];
                cnt++;
            }
        }
    }
    for(int i=1;i<=n;i++){
    int flag=0;
        for(int j=1;j<=m;j++){
            if(b[i][j]==ttt){
                cout<<j<<" "<<i;
                flag=1;
                break;
            }
        }
        if(flag) break;
    }
    return 0;
}
