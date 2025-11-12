#include <bits/stdc++.h>

using namespace std;
int a[10+5][10+5],mn,n,m,c,r,xr,xrxb,x=1,y=1,cnt;
int b[100+10];
bool flag=false;
int cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    mn=m*n;
    cin>>xr;
    b[1]=xr;
    for(int i=2;i<=mn;i++){
        cin>>b[i];
    }
    sort(b+1,b+1+mn,cmp);
    for(int i=1;i<mn;i++){
        if(b[i]==xr){
            xrxb=i;
            break;
        }
    }
    while(xrxb--){
        if(cnt<=xrxb){
            if(x%2!=0){
            if(y==n){
                x++;flag=true;
            }else{
                y++;
            }
            cnt++;
        }else{
            if(y==1){
                x++;flag=false;
            }else{
                y--;
            }
            cnt++;
        }
        }else{
            c=y;
            r=x;
            break;
        }

    }
    cout<<c<<" "<<r;

    return 0;
}
