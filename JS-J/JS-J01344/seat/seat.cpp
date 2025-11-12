#include<bits/stdc++.h>
using namespace std;
int n,m,r,c;
int a[105*105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)  cin>>a[i];
    int sc=a[1],t;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==sc){
            t=i;  break;
        }
    }
    if(t%n==0)  c=t/n;
    else  c=t/n+1;
    if(c%2==0)  r=n-t%n+1;
    else if(t%n!=0) r=t%n;
    else  r=n;
    cout<<c<<' '<<r<<endl;
    return 0;
}
