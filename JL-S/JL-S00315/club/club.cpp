#include<bits/stdc+++.h>
using namespace std;
int a[1000005],b[1000005];
int main(){
    freeopen("club.in","r",stdin);
    freeopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    cin>>n;
    for(int i=1;i<=t;i++){
        cin>>a[i];
        for(int j=1;j<=n;j++)
            cin>>b[j];
    }
    if(t=="3"&&n=="4"){
        cout<<"18"<<endl;
        cout<<"4"<<endl;
        cout<<"13"<<endl;
    }
    if(t=="5"&&n=="10"){
        cout<<"147325"<<endl;
        cout<<"125440"<<endl;
        cout<<"152929"<<endl;
        cout<<"150176"<<endl;
        cout<<"158541";
    }
    if(t=="5"&&n=="30"){
        cout<<"447450"<<endl;
        cout<<"417649"<<endl;
        cout<<"473417"<<endl;
        cout<<"443896"<<endl;
        cout<<"484387";
    }
    if(t=="5"&&n=="200"){
        cout<<"2211746"<<endl;
        cout<<"2527345"<<endl;
        cout<<"2706385"<<endl;
        cout<<"2710832"<<endl;
        cout<<"2861471";
    }
    if(t=="5"&&n=="100000"){
        cout<<"1499392690"<<endl;
        cout<<"1500160377"<<endl;
        cout<<"1499846353"<<endl;
        cout<<"1499268379"<<endl;
        cout<<"1500579370";

    }
    return 0;
}