#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],b[105][105],ans;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    ans=a[1];
    sort(a+1,a+n*m+1,cmp);
    int r=1,c=1,cnt=0;
    for(int i=1;i<=n*m;i++){
        b[r][c]=a[i];
        if(cnt%2==0)r++;
        else r--;
        if(r>n){
            c++;
            r--;
            cnt++;
        }
        if(r==0){
            r++;
            c++;
            cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==ans){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}