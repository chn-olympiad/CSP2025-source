#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int l[n+5]={0};
    int a[n+5]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[i]=l[i-1]+a[i];
    }
    int m=0;
    for(int i=1;i<=n;i++){
        m=max(m,a[i]);
    }
    int c=0;
    if(m*2<a[n]){
        c++;
    }
    cout<<c;
    return 0;
}
