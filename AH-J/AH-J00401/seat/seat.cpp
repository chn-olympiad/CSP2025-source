#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],r,h,l;
bool cmp(const long long &x,const long long &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(long long i=1;i<=n*m;i++){
        if(a[i]==r){
            r=i;
            break;
        }
    }
    l=(long long)((r*1.0+n-0.1)/n);
    h=r%n;
    if(h==0)h=n;
    if(l%2==0)h=n+1-h;
    cout<<l<<" "<<h;
    return 0;
}
