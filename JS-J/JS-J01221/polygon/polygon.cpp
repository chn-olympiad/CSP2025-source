#include<bits/stdc++.h>
using namespace std;
long long i,n,a[6000],an,b[6000],p,q;
void f(long long x){
    if(x<1)return ;
    p+=a[x];
    q++;
    f(x-1);
    if(p>a[i]&&q>=2)an++;
    p-=a[x];
    q--;
    f(x-1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++)b[i]+=b[i-1]+a[i];
    for(i=3;i<=n;i++){
        if(a[i]<b[i-1])f(i-1);
    }
    cout<<an;
    return 0;
}
