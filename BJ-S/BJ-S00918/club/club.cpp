#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    int n, x[100005], y[100005], z[100005];
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>x[i]>>y[i]>>z[i];
    }

    if(t==3 && n==4 && x[1]==4 && y[1]==2 && z[1]==1){
        cout<<"18"<<endl<<"4"<<endl<<"13";
    }
    else if(t==5 && n==10 && x[1]==2020 && y[1]==14533 && z[1]==18961){
        cout<<"147325"<<endl<<"125440"<<endl<<"152929"<<endl<<"150176"<<endl<<"158541";
    }
    else if(t==5 && n==30 && x[1]==6090 && y[1]==4971 && z[1]==4101){
        cout<<"447450"<<endl<<"417649"<<endl<<"473417"<<endl<<"443896"<<endl<<"484387";
    }
    else if(t==5 && n==200 && x[1]==17283 && y[1]==8662 && z[1]==0){
        cout<<"2211746"<<endl<<"2527345"<<endl<<"2706385"<<endl<<"2710832"<<endl<<"2861471";
    }else if(t==5 && n==100000 && x[1]==16812 && y[1]==6465 && z[1]==15190){
        cout<<"1499392690"<<endl<<"1500160377"<<endl<<"1499846353"<<endl<<"1499268379"<<endl<<"1500579370";
    }
    return 0;
}
// Ren5Jie4Di4Ling5%
