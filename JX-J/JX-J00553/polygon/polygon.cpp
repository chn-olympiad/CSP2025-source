#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int a,b,c,d;
    cin>>a>>b>>c;
    if(a+b+c>max(a,max(b,c)))cout<<1;
    else cout<<0;
    return 0;
}
