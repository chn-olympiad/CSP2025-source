#include<bits/stdc++.h>
using namespace std;
int n,m,sc,pm,c=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++)
        cin>>a[i];
    sc=a[0];
    sort(a,a+n*m);
    for(int i=n*m-1;i>=0;i--)
        if(a[i]==sc)
            pm=i;
    pm=n*m-pm;
    c+=pm/(2*n)*2;
    pm=pm%(2*n);
    if(pm==0)
        cout<<c-1<<' '<<1;
    else{
        if(pm>=1&&pm<=n)
            cout<<c<<' '<<pm;
        if(pm>=n+1&&pm<=2*n-1)
            cout<<c+1<<' '<<2*n-pm+1;
    }
    return 0;
}
