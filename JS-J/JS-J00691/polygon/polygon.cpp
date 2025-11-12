#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3*5+10;
int a[maxn],n,f[maxn];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(a[1]+a[2]+a[3]>a[1]*2)cout<<1;
    else cout<<0;
    return 0;
}
