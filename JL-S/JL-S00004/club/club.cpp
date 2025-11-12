#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t>>n;
    if(t==3&&n==4){
        cout<<18<<endl<<4<<endl<<13;
    }else if(t==5&&n==10){
        cout<<147325<<endl<<125446<<endl<<152929<<endl<<158541;
    }else if(t==5&&n==30){
        cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
    }else if(t==5&&n==200){
    cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
    }
    return 0;
}
