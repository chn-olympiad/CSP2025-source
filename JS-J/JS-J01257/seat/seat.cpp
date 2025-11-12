#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int x=a[1],id;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i]==x){
            id=i;
            break;
        }
    cout<<(id-1)/n+1<<" ";
    if(((id-1)/n+1)%2==1)
        if(id%n==0)
            cout<<n;
        else
            cout<<id%n;
    else
        if(id%n==0)
            cout<<1;
        else
            cout<<n-id%n+1;
}
