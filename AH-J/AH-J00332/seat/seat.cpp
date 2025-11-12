#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,s,c,r;
bool cmp(int y,int z){
    return y>z;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            s=i;
            break;
        }
    }
    c=ceil(s*1.0/n);
    r=(s%n==0?n:s%n);
    cout<<c<<" "<<(c%2!=0?r:n-r+1);
    return 0;
}
