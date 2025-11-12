#include<bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;
bool f(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x=n*m;
    int a[x];
    ios::sync_with_stdio(false);
    for(int i=0;i<x;i++){
        cin>>a[i];
    }
    int k=a[0],d=0;
    sort(a,a+x,f);
    for(int i=0;i<x;i++){
        if(a[i]==k){
            d=i;
            break;
        }
    }
    if(d+1<=m)
        cout<<1<<" "<<d+1;
    else
        cout<<1+(d+1)/n<<" "<<(d+1)%m;
    return 0;
}
