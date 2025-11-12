#include<bits/stdc++.h>
using namespace std;
long long m,n,a[10005],myselff=0,b[10005][10005],txt=1;
bool cmp(int aa,int bb){
    return aa>bb;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int j=1;j<=m*n;j++){
            cin>>a[j];
        }
    myselff=a[1];
    sort(a+1ll,a+m*n+1ll,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i%2==1){
                b[j][i]=a[txt];
                txt++;
            }
            else{
                b[n-j+1][i]=a[txt];
                txt++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==myselff){
                cout<<j<<" "<<i;
            }
        }
    }

    return 0;
}
