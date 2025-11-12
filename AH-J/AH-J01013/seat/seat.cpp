#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],r,ri,x,y=1,f;
bool cmp(long long q,long long w){
    return q>w;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++) cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(long long i=1;i<=n*m;i++) if(a[i]==r) ri=i;
    while(ri--){
        if(!f&&x==n||f&&x==1){
            y++;
            if(f) f=0;
            else f=1;
        }
        else if(f) x--;
        else x++;
    }
    cout<<y<<" "<<x;
    return 0;
}
