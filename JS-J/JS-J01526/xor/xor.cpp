#include<bits/stdc++.h>
using namespace std;
int n,k,a[100009];
int ejz(int x){
    long long sum=0;
    if(x>0){
        for(int i=1;x>0;i++){
            a[i]=x%2;
            x/=2;
        }
        for(int i=n;i>=1;i--)sum=sum*10+a[i];
    }
    if(x==0)sum=0;
    return sum;
}
long long yihuo(int x,int y){
    long long sum=0;
    long long z;
    x=ejz(x);
    y=ejz(y);
    while(x>0||y>0){
        if(x%10==y%10)z=0;
        else z=1;
        x/=10;
        y/=10;
        sum=sum*2+z;
    }
    return sum;
}
int main(){

    int sum=0;
    cin>>n>>k;

    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++){
        if(a[i]==k)sum++;
        else if(yihuo(a[i],a[i+1])==k){
                sum++;
                i++;
        }
    }
    cout<<sum;
    return 0;
}
