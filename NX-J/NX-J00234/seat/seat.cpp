#include<bits/stdc++.h>
using namespace std;
int n,m,grade[122],t[12],fz;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&grade[i]);
    }
    int r=grade[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(grade[i]<grade[j]) swap(grade[i],grade[j]);
        }
    }
    for(int i=1;i<=n*m;i++){
        if(grade[i]==r) fz=i;
    }
    int x=0,y=0;
    if(fz==1){cout<<1<<" "<<1;return 0;}
    x=(fz+n-1)/n;
    if(x%2){
        if(fz==n){
            y=n;
        }
        else{
            y=fz%n;
        }
    }
    else{
        if(fz%n==0){
            y=1;
        }
        else{
            y=n-fz%n+1;
        }
    }
    cout<<x<<" "<<y;
    //zhong yu zuo dui le,tai bu rong yi le!
    /*int x=0,y=0,g=0,c=1;
    for(int i=1;i<=n*m;i++){
        g++;
        if(g==n+1)g=1,c++;
        if((i-1/n)%2==0) y=g;
        else y=n-g+1;
        seats[c][y]=grade[i];
    }
    for(int i=m;i>=1;i--){
        for(int j=1;j<=m;j++){
            cout<<seats[j][i]<<' ';
            ans[i][j]=
        }
        cout<<endl;
    }
    */
    return 0;
}

