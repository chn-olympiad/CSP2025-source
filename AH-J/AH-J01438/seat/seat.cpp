#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000000];
long long cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long h=n*m,k=0,cnt=0,ans=0;
    for(long long i=0;i<h;i++){
        cin>>a[i];
    }
    k=a[0];
    sort(a,a+h,cmp);
    for(long long i=0;i<h;i++){
        if(a[i]==k){
            ans=i+1;
            break;
        }
    }
    cnt=ans/n;
    long long j=ans%n;
    if(ans%n!=0){
        cnt++;
    }
    if(j==0&&cnt%2==0){
        cout<<cnt<<" "<<1;
    }else if(j==0&&cnt%2!=0){
        cout<<cnt<<" "<<n;
    }else if(j!=0&&cnt%2==0){
        cout<<cnt<<" "<<n-j+1;
    }else{
        cout<<cnt<<" "<<j;
    }
    return 0;
}
