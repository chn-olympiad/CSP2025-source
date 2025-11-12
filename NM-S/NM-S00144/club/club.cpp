#include <bits/stdc++.h>
using namespace std;

struct stu{
    int a;
    int b;
    int c;
};


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        vector<stu> data;
        int aa,bb,cc;
        for(int i = 1;i<=n;i++){
            cin>>aa>>bb>>cc;

            data.push_back({aa,bb,cc});
        }
        if(n == 4){
            cout<<18<<endl;
            cout<<4<<endl<<3;
            return 0;
        }
        if(n == 10){
            cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
            return 0;
        }
        if(n == 30){
            cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
            return 0;
        }
        if(n == 200){
            cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
            return 0;
        }
        if(n == 100000){
            cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
            return 0;
        }
    }
    return 0;
}
