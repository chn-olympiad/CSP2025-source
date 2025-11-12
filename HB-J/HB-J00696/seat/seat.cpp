#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,s,d;
    cin>>a>>s;
    int ud;
    int k[11][11];
    int p[11];
    cin>>d;
    ud=d;
    for(int i=1;i<=a*s;i++){
        cin>>d;
        for(int j=0;j<=i;j++)
            if(ud<=d)
                cout<<i<<" "<<j;
    }





    return 0;
}
