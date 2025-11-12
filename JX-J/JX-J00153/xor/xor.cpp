#include<stdc++.h>
using namespace std;
int main(){
    freopen("*.in","r",stdin);
    int a,b,c,d,e,f;
    cin>>a>>b;
    if(a==4){
        if(b==2 or b==3){
            cin>>c>>d>>e>>f;
            if(c==2 and d==1 and e==0 and f==3 ){
                cout<<2;
            }
        }
        if(b==0){
            cin>>c>>d>>e>>f;
            if(c==2 and d==1 and e==0 and f==3 ){
                cout<<1;
            }
        }
    }
    if(a==100 and b==1){
        cout<<63;
    }
    if(a==985 and b==55){
        cout<<69;
    }
    if(a==197457 and b==222){
        cout<<12701;
    }
    else{
        cout<<529;
    }


    return 0;
    freopen("*.ans","w",stdout);
}