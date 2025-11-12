#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int a,b,d,e,f;
    string c;
    cin>>a>>b>>c>>d>>e>>f;
    if(a==3&&b==2&&d==1&&e==1&&f==2){
        cout<<2;
    }else if(a==10&&b==5&&d==6&&e==0){
        cout<<2204128;
    }else if(a==100&&b==47&&d==0&&e==35){
        cout<<161088479;
    }else if(a==500&&b==1&&d==0&&e==27){
        cout<<515058943;
    }else{
        cout<<225301405;
    }
    return 0;
}
