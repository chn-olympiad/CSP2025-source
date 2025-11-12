#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,y,sum;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        sum+=bool(a[i]>a[0]);
    }
    x=ceil((sum+1)*1.0/n);
    y=(sum+1)%n;
    y=(y?y:n);
    cout<<x<<" ";
    cout<<(x%2?y:n-y+1);
    return 0;
}
