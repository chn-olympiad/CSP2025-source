#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int a,b[105];
/*struct node{
    int x,y;
};
node Find(int pos){
    int x=1,y=1;
    while(pos>=2*n){
        y+=2;
        pos-=n*2;
    }if(pos>=n){
        pos-=n;
        y++;
        x=n-pos;
        return {x,y};
    }else{
        x=pos;
        return {x,y};
    }
}*/
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    b[1]=a;
    for(int i=2;i<=n*m;i++){
        cin>>b[i];
    }sort(b+1,b+n*m+1);
    //for(int i=n*m;i>=1;i--){
    //    if(a==b[i]){
    //        int pos=n*m-i+1;
    //        node t=Find(pos);
    //        cout<<t.y<<" "<<t.x;
    //    }
    //}
    int x=1,y=1,t=1;
    for(int i=n*m;i>=0;i--){
        if(a==b[i]){
            cout<<y<<" "<<x;
            break;
        }x+=t;
        if(x>n){
            y++;
            t=-1;
            x=n;
        }if(x<1){
            y++;
            t=1;
            x=1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
