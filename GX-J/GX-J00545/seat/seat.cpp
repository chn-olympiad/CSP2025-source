#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int a[120];
    for(int i=1;i<=n*m;i++){
            cin>>a[i];
    }
    int x,y;
    for(int i=1;i<=n*m;i++){
        if(a[i]>a[i+1]){
            a[i+1]=x;
            a[i]=y;
            a[i+1]=y;
            a[i]=x;
        }
        else continue;
    }
    for(int i=1;i<=n*m;i++){
        cout<<a[i];
    }
    return 0;
}
