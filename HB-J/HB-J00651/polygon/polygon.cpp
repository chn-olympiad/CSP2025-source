#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
ll a[5004];
int main(){
    ll n,maxn=0,i=1,num=0;
    cin>>n;
    ll sum=n*(n+1)/2;
    while(i<=n){
        cin>>a[i];
        if(a[i]>maxn){
            maxn=a[i];
        }
        num+=a[i];
        i++;
    }
    maxn*=2;
    ll p=num,j=0;
    i=0;
    while(i<=n){
        while(j<=n){
            i++;
            if(num-a[i+j]<=maxn){
                sum=sum-i-j+n;
            }
            num-=a[i+j];
        }
        i++;
    }
    cout<<sum;
    return 0;
}
