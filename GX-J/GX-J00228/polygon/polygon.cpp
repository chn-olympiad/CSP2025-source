#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ans,l;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3)cout<<0;
    else if(n==3)cout<<1;
    else cout<<(n+3)*(n-2)/2;
    fclose(stdin);
    fclose(stdout);
}
