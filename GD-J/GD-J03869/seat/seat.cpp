#include<bits/stdc++.h>
using namespace std;
const int N=20;
int num[N][N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cnt=0,x=1,y=1,d=1;
    for(int i=1;i<=n*m;i++){
        num[x][y]=++cnt;
        if(x+d<1||x+d>n){
            ++y;
            d=-d;
        }
        else
            x+=d;
    }
    int rnk=1,val;
    cin>>val;
    for(int i=2,x;i<=n*m;i++){
        scanf("%d",&x);
        rnk+=(x>val);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(num[i][j]==rnk){
                cout<<j<<" "<<i<<endl;
                return 0;
            }
}