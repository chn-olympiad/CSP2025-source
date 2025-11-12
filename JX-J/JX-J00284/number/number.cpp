#include<bits/stdc++.h>
using namespace std;
long long s[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long a,n=0;
    cin>>a;
    while(a){
        s[n]=a%10;
        a=a/10;
        n++;
    }
    sort(1,n,n+s+1);
    for(long long i=0;i<n;i++){
        cout<<s[i];
    }
    return 0;
}
