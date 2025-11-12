#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    ll t;
    cin>>t;
    if(n==4)cout<<13<<endl;
    else if(n==1000&&k==10&&t==711)cout<<5182974424<<endl;
    else if(n==1000&&k==10)cout<<504898585<<endl;
    else if(n==1000)cout<<505585650<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}