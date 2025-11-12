#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],t=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int I=(i-1)*m+j;
            if(a[I]==t){
                cout<<i<<" ";
                if(i%2==0) cout<<m-j+1;
                else cout<<j;
            }
        }
    }
    return 0;
}
