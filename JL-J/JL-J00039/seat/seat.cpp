#include<bits/stdc++.h>
using namespace std;
int a[114514];
int mp[11][11];
int n,m,r,inde=1;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>r;
    a[1]=r;
    for(int i=2;i<=n*m;i++)cin>>a[i];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++){
        if(i%2){
            for(int j=1;j<=n;j++){
                mp[j][i]=a[inde++];
            }
        }else{
            for(int j=n;j>=1;j--){
                mp[j][i]=a[inde++];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==r){
                cout<<j<<' '<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}
