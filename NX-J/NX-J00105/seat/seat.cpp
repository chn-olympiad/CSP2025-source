#include<bits/stdc++.h>
using namespace std;
int a[1000][100];
int b[10000];
int n,m,g=0;
bool cmp(int ghfg,int tyty){
    return tyty<ghfg;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
        if(b[i]>g){
            g=b[i];
        }
    }
    int c=b[1];
    sort(b+1,b+n*m+1,cmp);


    int nx=1,ny=1,f=n,h=0;
    for(int i=1;i<=n*m;i++){
         a[nx][ny]=b[i];
         if(b[i]==c){
           cout<<ny<<' '<<nx<<endl;
           return 0;
        }
        if(h==0){
            nx++;
        }else{
            nx--;
        }

        if(nx>n){
            ny++;
            nx=n;
            if(h==0){
                h=1;
            }else if(h==1){
                h=0;
            }
        }


    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

