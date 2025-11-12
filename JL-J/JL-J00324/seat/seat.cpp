#include<bits/stdc++.h>
using namespace std;
long long N=10000006;
struct seat{
    int s;
    int x;
    int y;
}f[10000006];
int main( ){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,d=0;
    cin>>n>>m;
    long long a[N]={ };
    long long ans=0,sum=0;
    for(long long i=0;i<n*m;i++){
        cin>>a[i];
        if(i==0){
            d=a[i];
        }
    }
    sort(a+1,a+n*m+1);
    for(long long i=0;i<n*m;i++){
        f[i].s=a[i];
    }
    for(long long i=0;i<n*m;i++){
        sum++;
        if(sum==n+1){
            ans++;
            sum=0;
        }
        if(ans%2==0){
            if((i+1)%n==0){
                f[i].x=n;
            }
            else{
                f[i].x=(i+1)%n;
            }
        }
        else if(ans%2==1){
            if((i+1)%n==0){
                f[i].x=1;
            }
            else{
                f[i].x=n-+1;
            }
        }
        f[i].y=i/n+1;
        if(f[i].s=d){
            cout<<f[i].y<<" "<<f[i].x;
        }
    }
    return 0;
}

//#Shang4Shan3Ruo6Shui4
