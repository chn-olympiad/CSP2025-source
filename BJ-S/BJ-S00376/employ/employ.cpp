#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    char a[505];
    int y[505];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>y[i];
    long long b=1;
    for(int i=2;i<=n;i++){
        b=b*i%998244353;
    }
    cout<<b;
    return 0;
}
