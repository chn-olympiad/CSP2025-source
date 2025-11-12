#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],pos,t[15][15],cnt;
bool cmp(int x,int y){
return x>y;
}
signed main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
    if(i==1) pos=a[i];
}
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=m;i++){
    if(i%2){
        for(int j=1;j<=n;j++){
            t[i][j]=a[++cnt];
        }
    }else{
        for(int j=n;j>=1;j--){
            t[i][j]=a[++cnt];
        }
}
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(t[i][j]==pos){
            cout<<i<<' '<<j;
            return 0;
        }
    }
}
return 0;
}
