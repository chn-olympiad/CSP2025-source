#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int d,h;
}a[105];
bool cmp(node x,node y){
    return x.d>y.d;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].d;
        a[i].h=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int x=0,y=0;
    int k=0;
    while(a[k].h!=1){
        y++;
        if(y%2)
            for(int i=1;i<=n;i++){
                x++;
                if(a[++k].h==1)
                    break;
            }
        else
            for(int i=n;i>=1;i--){
                x--;
                if(a[++k].h==1)
                    break;
            }
    }
    cout<<y<<' '<<x<<'\n';
    return 0;
}
