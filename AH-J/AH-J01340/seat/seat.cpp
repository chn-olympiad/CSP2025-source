#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y,n,a[1010],s[15][15];
    cin>>x>>y;
    n=x*y;
    cin>>a[1];
    int R=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int tx=1,ty=0;
    for(int i=1;i<=n;i++){
        if(tx%2==1){
            ty++;
        }
        if(tx%2==0){
            ty--;
        }
        s[tx][ty]=a[i];
        if(tx%2==1&&ty==y&&i+1<=n){
            tx++;
            i++;
            s[tx][ty]=a[i];
            continue;
        }
        if(tx%2==0&&ty==1&&i+1<=n){
            tx++;
            i++;
            s[tx][ty]=a[i];
            continue;
        }

    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s[i][j]==R){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
	return 0;
}
