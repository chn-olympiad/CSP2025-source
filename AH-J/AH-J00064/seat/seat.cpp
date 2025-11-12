#include <bits/stdc++.h>
using namespace std;
const long long N  = 300;
long long n,m;
long long a[N];
long long cnt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(inlong longt i = 1;i<=n*m;i++){
        cin>>a[i];
    }
    long long x = a[1];
    cnt = 1;
    for(long long i = 2;i<=n*m;i++){
        if(a[i] > x){
            cnt++;
        }
    }
    long long l = (cnt+n-1) / n;
    long long h = cnt - (l-1) * n;
    if(l % 2 == 1){
        cout<<l<<" "<<h;
    }else{
        cout<<l<<" "<<n-h+1;
    }
    return 0;
}