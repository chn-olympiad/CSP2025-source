#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    int n,m,tot=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1])tot++;
    }
    int x=tot/n,y=tot%(2*n);
    if(y==0)cout<<x<<' '<<1;
    else if(y<n)cout<<x+1<<' '<<y;
    else if(y==n)cout<<x<<' '<<y;
    else cout<<x+1<<' '<<2*n-y+1;
    return 0;
}
