#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1005],x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+1+n*m);
    long long t,f,i;
    for(long long j=n*m;j>=1;j--){
        if(a[j]==x){
            i=(n*m-j)+1;
            t=((i-1)%m)+1;
            f=(i-t)/n+1;
            if(f%2==0){
                t=(m-t)+1;
            }
            cout<<f<<' '<<t;
            return 0;
        }
    }
}
