#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[105];
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x=0,y,r=0,c=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    x=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            y=i;
            break;
        }
    }
    //cout<<x<<" "<<y<<" ";
    c=(y-1)/n+1;
    if(c%2==1)r=(y-1)%n+1;
    else r=n-(y-1)%n;
    cout<<c<<" "<<r;
    return 0;
}
