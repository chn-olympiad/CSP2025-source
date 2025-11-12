#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b[110],x=1,y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a;
    b[a]=2;
    for(int i=2;i<=n*m;i++){
        cin>>a;
        b[i]++;
    }
    a=1;
    for(int i=1;i<=n*m;i++){
        if(b[i]==1);
        {
            x+=a;
            if(x==n+1){
                a*=-1;
                x=n;
                y++;
            }
            else if(x==0){
                a*=-1;
                x=1;
                y++;
            }
        }
        if(b[i]==2){
            break;
        }
    }
    cout<<y<<' '<<x;
    return 0;
}
