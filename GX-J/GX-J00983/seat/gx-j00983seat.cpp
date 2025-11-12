#include <bits/stdc++.h>
using namespace std;
int n,m,a,c,e,m1;
int main(){
    freopen("seat.in.","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a;
    m1=m;
    int b[n*m],d[n*m];
    for (int i=1;i<=m*n;i++){
        cin>>b[i];
    }
    for (int i=1;i<=n*m;i++){
        for (int j=i;j<=n*m;j++){
            if (b[j]>c)c=b[i];
        }
        d[i]=c;
    }
    for (int i=1;i<=n*m;i++){
        if (a>=d[i]){
            a=i;
            e=1;
        }
    }
    if (e!=1)a=m*n;
    m=e%n;
    if (m%2==0)m=m1-m+1;
    n=e/n;
    cout<<m<<n;
    return 0;
}
