#include<bits/stdc++.h>
using namespace std;
int n,m,t,q,r;
int a[10006];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int p=a[1];
    sort(a+1,a+m*n+1);
    for(int i=1;i<=m*n;i++){
        if(a[i]==p){
            t=n*m-i+1;
            break;
        }
    }
    //cout<<t<<" ";
    if(t%n==0)r=t/n;
    else r=t/n+1;
    if(r%2==1)
    {
        if(t%n==0)q=n;
        else q=t-(r-1)*n;

    }
    else{
        if(t%n==0)q=1;
        else q=n+1-t+(r-1)*n;
    }
    cout<<r<<" "<<q;
    return 0;
}
