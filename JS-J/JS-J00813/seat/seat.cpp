#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2000005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat,out","w",stdout);
    cin>>n>>m;
    long long xy=0;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            xy++;
        }
    }
    xy++;
    long long x=xy/n;
    if(xy<=n){
        cout<<1<<" ";
        x=1;
    }
    if(xy>n){
        if(xy%n==0){
            cout<<x<<" ";
        }
        if(xy%n!=0){
            x++;
            cout<<x<<" ";
        }
    }
    long long l=n*x;
    if(x%2==0){
        cout<<l-xy+1;
    }
    if(x%2!=0){
        cout<<n-l+xy;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

