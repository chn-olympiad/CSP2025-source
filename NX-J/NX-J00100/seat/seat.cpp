#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("saet.in","r",stdin);
    freopen("saet.in","r",stdin);
    int n,m;
    cin>>n>>m;
    int a[n*m+1],n1;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int ans=a[1];
    sort(a,a+n*m);
    for(int i=1;i<=n*m;i++){
        if(a[i]==ans){
            n1=i;
            break;
        }
    }
    int y=n1/m;
    int x;
    if(y%2==1)
        x=n1%m;
    else
        x=n-n1%m;
    cout<<x<<" "<<y;
    return 0;
}
