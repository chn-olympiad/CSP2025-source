#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,s=0,a[10000],i;
    cin>>n>>m;
    s=n*m;
    for(int i=1;i<=s;i++){
        cin>>a[i];
    }
    for(int i=1;i<=s;i++){
        if(n==1&&m==1){
        cout<<1<<" "<<1;
        }
        else if(n==2&&m==1){
            if(a[i]>a[i+1])
                cout<<1<<" "<<1;
            else
                cout<<2<<" "<<1;
        }
        else if(n==1&&m==2){
            if(a[i]>a[i+1])
                cout<<1<<" "<<1;
            else
                cout<<1<<" "<<2;
        }
    }
    cout<<n*m-i+1;
    return 0;
}
