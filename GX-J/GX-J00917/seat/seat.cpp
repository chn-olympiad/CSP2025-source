#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[10005];

int cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>a[(i-1)*m+j];
    ans=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[(i-1)*m+j]==ans){
                if(i%2==1) cout<<i<<" "<<j<<endl;
                else cout<<i<<" "<<m-j+1;
                return 0;
            }
        }
    }
    return 0;
}
