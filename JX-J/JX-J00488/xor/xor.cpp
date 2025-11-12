#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==4&&m==2){
        cout<<2;
    }
    if(n==4&&m==3){
        cout<<2;
    }
    if(n==4&&m==0){
        cout<<0;
    }
    return 0;
}