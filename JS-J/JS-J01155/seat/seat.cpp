#include<bits/stdc++.h>
using namespace std;
int n,m;
int x;
int st=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    for(int i=2;i<=n*m;i++){
        int a;
        cin>>a;
        if(a>x)st++;
    }
    int l=st/n;
    if(st%n!=0)l++;
    int h=(st-1)%n+1;
    if(l%2==0)h=n-h+1;
    cout<<l<<" "<<h;
    return 0;
}
