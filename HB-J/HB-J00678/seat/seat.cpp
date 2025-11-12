#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
pair<int,int>p[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>p[i].first;
        p[i].second=i;
    }
    sort(p+1,p+1+n*m);
    int x=1,y=1,id=n*m,dir=0;
    while(p[id].second!=1){
        id--;
        if(dir){
            x--;
            if(x<1){
                x++;y++;
                dir=0;
            }
        }
        else{
            x++;
            if(x>n){
                x--;y++;
                dir=1;
            }
        }
    }
    cout<<y<<' '<<x;
    return 0;
}