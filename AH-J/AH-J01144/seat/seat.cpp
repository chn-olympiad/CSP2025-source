#include<bits/stdc++.h>
using namespace std;
int seat[15][15],p[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>p[i];
    int g=p[1],num;
    sort(p+1,p+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(p[i]==g) num=i;
    }
    int c=(num+n-1)/n,yu=num%n,r;
    if(c%2==1)
        r=num-(c-1)*n;
    else r=n-yu;
    cout<<c<<' '<<r;
    return 0;
}
