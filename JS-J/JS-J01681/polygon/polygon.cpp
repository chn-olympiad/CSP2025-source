#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int maxx=max(max(a,b),c);
    int temp=a+b+c;
    if(temp>2*maxx){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
//1-3
