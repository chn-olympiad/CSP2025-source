#include <bits/stdc++.h>
using namespace std;
int a[105],p[15][15],n,m,a1=0,p1;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a1;
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }
    int x=1,y=1,k=1;
    while(y<=m or x<n){
        p[x][y]=k;
        k++;
        if(y%2==1){
            x++;
        }
        else{
            x--;
        }
        if(x>n and y%2==1){
            x=n;y++;
        }
        else if(x<1 and y%2==0){
            x=1;y++;
        }
    }
    sort(a+1,a+(n*m),cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]<a1){
            p1=i;
            for(int ii=1;ii<=n;ii++){
                for(int j=1;j<=m;j++){
                    if(p[ii][j]==p1){
                        cout<<j<<" "<<ii;
                        return 0;
                    }
                }
            }
            return 0;
        }
    }
    return 0;
}
