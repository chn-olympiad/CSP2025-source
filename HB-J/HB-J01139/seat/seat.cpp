#include<bits/stdc++.h>
using namespace std;
int n,m,a[20][20],b[110],c,d,e,num;
int ent(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
        num=b[1];
    }
    sort(b+1,b+n*m+1,ent);
    for(int i=1;i<=n*m;i++){
        if(b[i]=num){
            c=i;
        }
    }
    d=1+c/n;
    if(d>1 && d%2==0){
        e=n-c%n+1;
    }else if(d>1 && d%2!=0){
        e=c%n;
    }else if(d<=1){
        e=c;
    }
    cout<<d<<" "<<e;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
