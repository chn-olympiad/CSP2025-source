#include<bits/stdc++.h>
using namespace std;
int m,n,s,t=0,c,d=1,f=0;
int a[15][15];
int b[110];
int cmp(int x,int y){
   return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>b[i];
    }
    s=b[1];
    sort(b+1,b+m*n+1,cmp);
    for(int i=1;i<=m;i++){
       if(t==0){
            c=1;
            while(c>=1 && c<=n){
                if(b[d]==0){
                    f=1;
                    break;
                }
                a[i][c]=b[d];
                d++;c++;
            }
       }else{
            c=n;
            while(c>=1 && c<=n){
                if(b[d]==0){
                    f=1;
                    break;
                }
                a[i][c]=b[d];
                d++;c--;
            }
       }
       if(f==1){
            break;
       }
       if(t==0){
            t=1;
       }else{
            t=0;
       }

    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==s){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
