#include<bits/stdc++.h>
using namespace std;
int n,m,a[99][99],s[999],t;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];s[i]*=-1;
    }t=0-s[1];


    sort(s+1,s+1+m*n);

    int x=1,y=1,xia=1;
    for(int i=1;i<=m*n;i++){
        a[x][y]=-s[i];
        if(a[x][y]==t){
            cout<<y<<" "<<x<<endl;
            return 0;

        }
        if(n==1){
            y++;
        }else if(m==1){
            x++;
        }else{
            //tian wan x,y
            if(xia==1&&x<n)x++;
            else if(xia==1&&x==n)y++,xia=0;
            else if(xia==0&&x>1)x--;
            else if(xia==0&&x==1)y++,xia=1;
        }


    }
    return 0;
}
