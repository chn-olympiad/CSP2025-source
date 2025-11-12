#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,c=1,r=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            if(r%2==1)c++;
            if(r%2==0)c--;
        }
        if(c==0)r++,c=1;
        else if(c==n+1)r++,c=n;
    }
    cout<<r<<" "<<c;
    return 0;
}
