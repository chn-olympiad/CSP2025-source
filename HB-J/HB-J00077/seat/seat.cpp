#include<bits/stdc++.h>
using namespace std;
int n,m,b,x,y,cnt;
int a[15][15],p[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>p[i];
    }
    b=p[1];
    sort(p+1,p+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2){
            for(int j=1;j<=n;j++){
                cnt++;
                a[j][i]=p[cnt];
            }
        }else{
            for(int j=n;j>=1;j--){
                cnt++;
                a[j][i]=p[cnt];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==b){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
