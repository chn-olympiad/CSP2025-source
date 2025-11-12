#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n*m;++i)cin>>a[i];
    int a1=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int pos=0;
    for(int i=1;i<=n*m;++i){
        if(a[i]==a1){
            pos=i;break;
        }
    }
    int c=(pos-1)/n+1,r=(pos-1)%n+1;
    if(c%2==0){
        r=n-r+1;
    }cout<<c<<' '<<r<<endl;
    return 0;
}