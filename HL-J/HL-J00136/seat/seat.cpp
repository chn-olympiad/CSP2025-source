#include<bits/stdc++.h>
using namespace std;
long long n, m, a[105],x,b,c;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long nm=n*m;
    for(int i = 1;i<=nm;i++)
        cin>>a[i];
    x=a[1];
    sort(a,a+nm+1);
    int nu = 1;
    for(int i = nm;i>=1;i--){
        if(a[i]==x){
            x=nu;
            break;
        }
        nu++;
    }
    if(x%n==0)
        b=x/n;
    else
        b=x/n+1;
    int num = x-n*(b-1);
    if(b%2==1)
        c=num;
    else
        c=n-num+1;
    cout<<b<<" "<<c;
    return 0;
}
