#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],p,f,w,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    p=n*m;
    for(int i=1;i<=p;i++)
        cin>>a[i];
    f=a[1];
    sort(a+1,a+p+1,greater<int>());
    for(int i=1;i<=p;i++)
        if(a[i]==f) w=i;
    if(w<=n){
        cout<<"1"<<" "<<w;
        return 0;
    }
    int x=w/n;
    int y=w%n;
    if(y!=0) c=x+1;
    else c=x;
    if(c%2!=0){
        if(y!=0) r=y;
        else r=n;
    }
    else{
        if(y!=0) r=n-(y-1);
        else r=1;
    }
    cout<<c<<" "<<r;
    return 0;
}
