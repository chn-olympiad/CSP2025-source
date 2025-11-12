#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int a[11][11];
int s[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=m*n;i++){
        cin>>s[i];
    }
    ans=s[1];
    sort(s+1,s+1+(m*n),cmp);
    int i=1;
    for(int h=1;h<=m;h++){
        if(h%2==1){
            for(int l=1;l<=n;l++){
                a[l][h]=s[i];
                i++;
            }
        }else{
            for(int l=n;l>=1;l--){
                a[l][h]=s[i];
                i++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==ans){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
