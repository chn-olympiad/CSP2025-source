#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[15],n,p,m,x=1,y=1,o;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    p=b[1];
    sort(b+1,b+1+n*m,cmp);
    n=n*m;
    while(o<=n){
        o++;
        a[x][y]=b[o];
        if(p==b[o]){
            cout<<x<<" "<<y;
            return 0;
        }
        if(x%2){
            y++;
        }else{
            y--;
        }
        if(x%2==1&&y==m+1){
            x++;
            y=m;
        }
        if(x%2==0&&y==0){
            x++;
            y=1;
        }
    }
    return 0;
}
