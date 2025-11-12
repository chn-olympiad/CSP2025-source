#include<bits/stdc++.h>
using namespace std;
long long a[10005];
long long n,m;
int cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    long long u=a[0];
    long long k;
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
          if(a[i]==u)k=i+1;
    }
    long long sum=k/n;
    long long y=k%n;
    if(y==0){
        if(sum%2==0){
            cout<<sum<<" "<<1;
        }else{
            cout<<sum<<" "<<n;
        }
    }else{
        if(sum%2==0){
            cout<<sum+1<<" "<<y;
        }else{
            cout<<sum+1<<" "<<n-y+1;
        }
    }
    return 0;
}
