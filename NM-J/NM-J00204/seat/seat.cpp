#include <bits/stdc++.h>
#define in "seat.in"
#define out "seat.out"
using namespace std;
bool cmp(int m,int n){
    return m>n;
}
int main(){
    freopen(in,"r",stdin);
    freopen(out,"w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int fnd=a[1][1];
    bool flag;
    sort(a[0][0],a[n][m],cmp);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==fnd){
                flag=1;
                cout<<i<<j;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    
    return 0;
}