#include<bits/stdc++.h>
using namespace std;
long long a,b,c,c2=0,c3=0,d=0,e1=0,e2=0,e3=0,f=1,g;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>a>>b>>c;
    for(int i=1;i<=a;i++){
        cin>>d;
        f*=i;
    }
    cout<<f;

    return 0;
}
