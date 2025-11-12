#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long s,n=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(nullptr);cin.tie(nullptr);
    cin>>s;
    while(s!=0){
        n++;
        a[n]=s%10;
        s/=10;
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
