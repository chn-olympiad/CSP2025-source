#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],marks,cnt=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>marks;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>marks) cnt++;
    }
    int c=cnt/n;
    int d=cnt%n;
    if(d==0){
        cout<<c<<" ";
        if(c%2==1) cout<<n;
        else cout<<1;
    }
    else{
        c+=1;
        cout<<c<<" ";
        if(c%2==1) cout<<d;
        else cout<<n-d+1;
    }
    return 0;
}
