#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,r,a[110],f;
bool cmp(const ll &x,const ll &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1) f=a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==f) r=i;
    }
    ll y=r/n,x;
    y++;
    if(r%n==0) y--;
    if(y%2==1){
        x=r%n;
        if(x==0) x=n;
    }
    else{
        x=n-(r%n)+1;
        if(x>n) x=1;
    }
    cout<<y<<" "<<x;
    return 0;
}

