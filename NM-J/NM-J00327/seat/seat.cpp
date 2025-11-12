#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[250]={0};
int s[15][15]={0};
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int j=1;j<=m;j+=2){
        for(int i=1;i<=n;i++){
            s[i][j]=a[n*(j-1)+i];
            if(s[i][j]==t){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    for(int j=2;j<=m;j+=2){
        for(int i=n;i>=1;i--){
            s[i][j]=a[(n-i+1)+n*(j-1)];
            if(s[i][j]==t){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
