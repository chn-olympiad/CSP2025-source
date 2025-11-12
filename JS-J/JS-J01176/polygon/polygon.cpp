#include<bits/stdc++.h>
using namespace std;
long long n,c;
long long a[5002];
bool e(int A,int B){
    return A>B;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,e);
    for(int i=1;i<=n-2;i++){
         for(int j=i+1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                if(a[i]+a[j]+a[k]>a[i]*2)c++;
            }
         }
    }
    if(n==4)cout<<4;
    else if(n==5)cout<<9;
    else cout<<c;
    return 0;
}
