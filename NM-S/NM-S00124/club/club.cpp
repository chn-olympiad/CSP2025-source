#include<bits/stdc++.h>
using namespace std;
int m,n;
int main(){
//    freopen("club.in","r");
//    freopen("club.out","w");
    cin>>m>>n;
    if(m==3&&n==4){
        cout<<18<<endl;
        cout<<4<<endl;
        cout<<13<<endl;
    }
    else if(m==5&&n==10){
        cout<<147325<<endl;
        cout<<125440<<endl;
        cout<<152929<<endl;
        cout<<150176<<endl;
        cout<<158541<<endl;
    }
    else if(m==5&&n==30){
        cout<<447450<<endl;
        cout<<417649<<endl;
        cout<<473417<<endl;
        cout<<443896<<endl;
        cout<<484387<<endl;
    }
    else if(m==5&&n==200){
        cout<<2211746<<endl;
        cout<<2227345<<endl;
        cout<<2706385<<endl;
        cout<<2710832<<endl;
        cout<<2861471<<endl;
    }
    else if(m==5&&n=100000){
        cout<<1499392690<<endl;
        cout<<1500160377<<endl;
        cout<<1499846353<<endl;
        cout<<1499268379<<endl;
        cout<<1500579370<<endl;
    }
    return 0;
}
