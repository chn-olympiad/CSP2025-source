#include<bits/stdc++.h>
using namespace std;


int n,m;
int a[15][15],s[105],r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    r=s[1];
    sort(s+1,s+n*m+1);
    int x=1,y=1;
    for(int i=n*m;i>=1;i--){
        a[x][y]=s[i];
        if(x%2==1){
            y++;
            if(y>n){
                y=n;
                x++;
            }
        }else if(x%2==0){
            y--;
            if(y<1){
                y=1;
                x++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[j][i]==r){
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
