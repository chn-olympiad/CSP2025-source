#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,c=1,r=1,e;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[101];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    for(int i=1;i<n*m;i++){
        for(int j=1;j<n*m;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(t==a[i])
            e=i;
    }
    for(int i=1;i<=m;i++){
        if(e<=n)
            break;
        else{
            e-=n;
            c++;
        }
    }
    if(c%2==0){
        r+=n-e;
    }
    else{
        r=e;
    }
    cout<<c<<" "<<r;
    return 0;
}
