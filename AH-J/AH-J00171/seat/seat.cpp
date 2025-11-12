#include<bits/stdc++.h>
using namespace std;
int a[100][100],b[100005];
bool cmp(int c,int d){
    return c>d;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int r;
    cin>>r;
    for(int i=2;i<=m*n;i++){
        cin>>b[i];
    }
    b[1]=r;
    sort(b+1,b+1+n*m,cmp);
    int chang=1,kuan=1,bo=1,i=1;
    while(bo<=n*m){
        for(;i<=n;i++){
            a[i][chang]=b[bo];
            bo++;
        }
        i--;
        chang++;
        for(;i>=1;i--){
            a[i][chang]=b[bo];
            bo++;
        }
        i++;
        chang++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==r){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}

