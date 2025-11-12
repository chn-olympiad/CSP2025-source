#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d=1;
string f;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>a>>b;
    if(a==b){
        cout<<0;
    }else{
        for(int i=1;i<=a;i++){
            cin>>c;
        }
        for(int j=1;j<=a;j++){
            d=(d*j)%998244353;
        }
        cout<<d;
    }

    return 0;
}
