#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b,c,n;
    cin>>n;
    cin>>a>>b>>c;
    int cnt=max(a,max(b,c)),cnt1=a+b+c-cnt;
    if(cnt>cnt1){
        cout<<0;
    }else cout<<1;
    return 0;
}

