#include<bits/stdc++.h>
using namespace std;
int n,m,a[11*11];
bool cmp(int a,int b){return a>b;}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
    cin>>n>>m;
    int whe=1;
    for(int i=1;i<=n*m;++i){
        cin>>a[i];
        if(a[i]>a[1]) whe++;
    }
    // cout<<whe<<'\n';
    int h=whe/n+((whe%n)!=0);
    cout<<h<<' '<<((h&1)?((whe%n)?whe%n:n):((whe%n)?n-whe%n+1:1));
    return 0;
}
//((h&1)?((whe%n)?whe%n:n):((whe%n)?n-whe%n+1:1))