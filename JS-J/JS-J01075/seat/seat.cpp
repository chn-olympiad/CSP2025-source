#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,cnt=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>a;
    for(int i=2;i<=n*m;i++){
        int b;
        cin>>b;
        if(b>a)cnt++;
    }
    int x=0,y=0;
    x=cnt/n+(cnt%n>0);
    int r=cnt%(n*2);
    if(r<=n&&r!=0)y=r;
    else if(r==0)y=1;
    else y=n*2-r+1;
    cout<<x<<' '<<y;
    return 0;
}
