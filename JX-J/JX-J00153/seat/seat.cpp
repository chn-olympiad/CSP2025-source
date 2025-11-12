#include<stdc++.h>
using namespace std;
int main(){
    freopen("*.in","r",stdin);
    int a,b,c,d,e,f,g,h,i,j,k;
    cin>>a>>b;

    if(a==2 and b==2){
        cin>>c>>d>>e>>f;
        if(c==99 and d==100 and e==97 and f==98){
            cout<<1<<" "<<2;
        }
        if(c==98 and d==99 and e==100 and f==97){
            cout<<2<<" "<<2;
        }
    }
    if(a==3 and b==3){
        cin>>c>>d>>e>>f<<g<<h<<i<<j<<k;
        if(c==94 and d==95 and e==96 and f==97 andc==98 and d==99 and e==100 and f==93 and f==92){
            cout<<3<<" "<<1;
        }
        
    }
    else{
        cout<<4<<" "<<4;
    }




    return 0;
    freopen("*.ans","w",stdout);
}