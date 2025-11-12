#include<bits/stdc++.h>
using namespace std;
int a[11451];
bool cmp(int a,int b){
    return a>b;
}
int ews[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int mb=a[1];
    sort(a+1,a+n*m+1,cmp);
    int tx;int ty;
    int x=1,y=1,op=1,pos=1;
    for(int i=1;i<=n*m;i++){
        ews[x][y]=a[pos];
        if(a[pos]==mb){
            cout<<y<<" "<<x;
            return 0;
        }
        x+=op;pos++;
        if(x>n){
            x=n;y++;op=-1;
        }
        if(x<1){
            x=1;y++;op=1;
        }
    }
}
