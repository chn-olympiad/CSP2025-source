#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int sum=m*n;
    int s[sum];
    for(int i=1;i<=sum;i++){
        cin>>s[i];
    }
    int k=s[1];
    int a;
    sort(s+1,s+sum+1);
    for(int i=1;i<=sum;i++){
        if(s[i]==k){
            a=sum-i+1;
        }
    }
    int x,y;
    if(a%n==0){
        x=a/n;
    }
    else{
        x=a/n+1;
    }
    if(x%2==0){
        y=n-x%n+1;
    }
    else{
        y=x%n+1;
    }
    cout<<x<<' '<<y;
    return 0;
}
