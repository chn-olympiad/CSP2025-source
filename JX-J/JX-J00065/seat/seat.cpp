#include<bits/stdc++.h>
using namespace std;
int n,m,a[20][20],b[400],x,z=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    x=b[1];
    sort(b+1,b+n*m+1,cmp);
    for(int i=1;i<=m;i+=2){
        for(int j=1;j<=n;j++){
            a[j][i]=b[z++];
        }
        for(int j=n;j>=1;j--){
            a[j][i+1]=b[z++];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==x) {
                cout<<j<<" "<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}
