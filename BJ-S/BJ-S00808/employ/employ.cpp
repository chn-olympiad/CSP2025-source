#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,m,a[501],r=1;
string s;
bool comp(int x,int y){
    return x>y;
}
int jie(int x){
    if(x<=1){
        return 1;
    }
    if(x==2){
        return 2;
    }
    return x*jie(x-1);
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<jie(n)/jie(n-m);
    return 0;
}
