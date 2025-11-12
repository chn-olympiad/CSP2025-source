#include<bits/stdc++.h>
using namespace std;
long long a[10005];
long long ans[10005];
long long mp[105][105];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long r;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    long long num=n*m;
    sort(a+1,a+num+1);
    long long idx;
    for(long long i=1;i<=num;i++){
        ans[i]=a[num-i+1];
        if(ans[i]==r){
            idx=i;
        }
    }
    long long x=0;
    long long y=1;
    for(long long i=1;i<=idx;i++){
        if(y%2==1){
           x++;
           if(x>n){
            x=n;
            y++;
           }
        }
        else{
            x--;
            if(x<1){
                x=1;
                y++;
            }
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
