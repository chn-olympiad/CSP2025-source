#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
long long a,b,c,d;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(b+c>d || b+d>c || c+d>b){
        cout<<1%N;
        return 0;
    }
    else cout<<"0";
    return 0;
}

