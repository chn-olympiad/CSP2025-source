#include <bits/stdc++.h>
using namespace std;
int n,m,a[110];
int cmp(int a,int b){
    return a>b;
}
//n is hang,m is lie
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int R=a[1],num=1,ry,rx;
    bool findr=0;
    sort(a+1,a+(n*m)+1,cmp);
    for(int y=1;y<=m;y++){
        if(y%2==1){
            for(int x=1;x<=n;x++){//x is hang,y is lie
                if(a[num]==R){
                    ry=y;
                    rx=x;
                    findr=1;
                    break;
                }
                num++;
            }
        }
        if(y%2==0){
            for(int x=n;x>=1;x--){
                if(a[num]==R){
                    ry=y;
                    rx=x;
                    findr=1;
                    break;
                }
                num++;
            }
        }
        if(findr) break;
    }
    cout<<ry<<" "<<rx;
    return 0;
}
