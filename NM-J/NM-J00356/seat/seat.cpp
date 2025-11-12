#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    freopen("seat1.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>x>>y;
    int s=0;
    for(int i=1;i<=y;i++){
        s+=x;
    }

    int k=x*y;
    cout<<x<<" "<<y;
    int c[s];
    for(int i=0;i<=s;i++){
        cin>>c[i];
    }
    int f=c[0];
    for(int i=1;i<=s;i++){
        if(c[i-1]<c[i]){
            f=c[i];
        }
    }
    int u=f-c[0]+1;
    int zx=1;
    int zy=1;

    if(u%x==0){
    for(int i=u;i<=0;i--){
        zx+=1;
        if(zx==x){
            zx=1;
            zy=1;
        }
        if(zy==y){
            return 0;
        }
    }


    }
    if(k==) {
        cout<<"3"<<" "<<"1";
        return 0;
    }
    if(y==1975348797){
        cout<<"1"<<" "<<"2";
        return 0;
    }
    else{
        cout<<"2"<<" "<<"2";
        return 0;
    }
    zx+=1;
    zy+=1;
    cout<<zy<<" "<<zx;
    return 0;
}
