#include<bits/stdc++.h>
using namespace std;
long long m,n,a[10005],b;
bool cmp(long long n,long long m){
    return n>m;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+1+(n*m),cmp);
    long long i=1;
    for(;i<=n*m;i++){
        if(a[i]==b)break;
    }
    long long h,l;
    if(i%n==0){
        h=i/n;
    }
    else {
        h=i/n+1;
    }
    i=i-(h-1)*n;

    if(n%2==0)l=n-i+1;
    else l=i;
    cout<<h<<" "<<l;

    return 0;
}
