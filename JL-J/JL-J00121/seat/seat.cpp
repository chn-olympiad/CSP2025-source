#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k[110]={},ansn=1,ansm=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
            cin>>k[i];
    }
    int v=k[1];
    bool t=true;
    sort(k+1,k+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(t){
            ansm++;
            if(ansm>n){
                ansn++;
                ansm=n;
                t=false;
            }
            if(k[i]==v){
                cout<<ansn<<" "<<ansm;
                return 0;
            }
        }else{
            ansm--;
            if(ansm==0){
                ansm=1;
                t=true;
                ansn++;
            }
            if(k[i]==v){
                cout<<ansn<<" "<<ansm;
                return 0;
            }
        }
    }
    return 0;
}
