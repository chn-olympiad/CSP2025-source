#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,b,cnt;
int x=1,y=1;
bool dir=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    for(int i=2;i<=n*m;i++){
        cin>>b;
        if(b>a) cnt++;
    }
    while(cnt--){
        if(x==1&&dir==1){y++;dir=0;}
        else if(x==n&&dir==0){y++;dir=1;}
        else if(dir==1) x--;
        else if(dir==0) x++;
    }
    cout<<y<<" "<<x;
    return 0;
}