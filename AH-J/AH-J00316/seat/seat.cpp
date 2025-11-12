#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s=1,t=n*m,x;
    int a[n+1][m+1],b[t];
    for (int i=0;i<t;i++){cin>>b[i]; x=b[0];}
    sort (b,b+m*n);
    t--;
    for (int i=1;i<=m;i++){
        if(s%2==0)  for(int j=n;j>=1;j--){if(j<1)break;  a[i][j]=b[t]; t--; if(a[i][j]==x){cout<<i<<" "<<j; break;}}
        else        for(int j=1;i<=n;j++){if(j>n)break;  a[i][j]=b[t]; t--; if(a[i][j]==x){cout<<i<<" "<<j; break;}}
        s++;
    }
    return 0;
}
