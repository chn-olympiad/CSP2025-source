#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[101];
    int sum=n*m;
    for(int i=1;i<=sum;i++){
        cin>>a[i];
    }
    int num=a[1],j=0;
    sort(a+1,a+1+sum);
    for(int i=1;i<=sum;i++){
        if(a[i]==num){
            j=sum-i+1;
        }
    }
    if(j<n){
        cout<<1<<" "<<j;
    }
    else if(j%n==0 && (j/n)%2==0){
            cout<<j/n<<" "<<1;
    }
    else if(j%n==0 && (j/n)%2!=0){
        cout<<j/n<<" "<<n;
    }
    else if(j%n!=0 && (j/n)%2!=0){
        cout<<j/n+1<<" "<<n;
    }
    else if(j%n!=0 && (j/n)%2==0){
        cout<<j/n+1<<" "<<1;
    }
    else if(j%n!=0 && (j/n)%2!=0){
            cout<<j/n+1<<" "<<n-j%n+1;
    }
    else if(j%n!=0 && (j/n)%2==0){
        cout<<j/n+1<<" "<<j%n;
    }
    return 0;
}
