#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[10005],k[105][105],ans,f=0;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    ans=a[1];
    sort(a+1,a+n*m+1,cmp);
    int l=1,r=1,c=1;
    while(l<=n){
        if(f==0){
            k[l][r]=a[c];
            r++;
            c++;
        }else{
            k[l][r]=a[c];
            r--;
            c++;
        }
        if(r>m){
            f=1;
            r--;
            l++;
        }
        if(r<1){
            f=0;
            r++;
            l++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(k[i][j]==ans){
                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
