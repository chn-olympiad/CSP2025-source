#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N],n,m,cnt,x=1,y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    for(int i=2;i<=n*m;i++)
        if(a[i]>a[1]) ++cnt;
    while(cnt--){
        if(x%2){
            if(y==n) ++x;
            else ++y;
        }
        else{
            if(y==1) ++x;
            else --y;
        }
    }
    cout<<x<<' '<<y;
    return 0;
}
