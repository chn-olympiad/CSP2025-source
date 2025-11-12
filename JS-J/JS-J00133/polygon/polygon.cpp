#include<bits/stdc++.h>
using namespace std;

long long a[5005];
long long s[5005];

long long he(int a){
    int sum=1;
    for(int i=1;i<=a;i++){
        sum=sum+i;
    }
    return sum;
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=0;
    sort(a, a+n);
    for(int i=0;i<n;i++){
        s[i]=s[i-1]+a[i];
    }
   sum=he(n)-he(3);
    cout<<sum;
    return 0;
}
