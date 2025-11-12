#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int man=n*m;
    int grade[man];
    int a1,a1loc;
    for(int i=0;i<man;i++) {cin>>grade[i];if(i==0) a1=grade[i];}

    for(int i=0;i<man;i++){
        for(int j=i+1;j<man;j++){
            if(grade[j]>grade[i]) swap(grade[j],grade[i]);
        }
    }
    for(int i=0;i<man;i++){
        if(a1==grade[i]) a1loc=i+1;
    }
    //jisuanmingciwancheng

    //kaishijisuandaan
    int lie,hang;
    //lie
    if(a1loc%n==0) lie=a1loc/n;
    else lie=a1loc/n+1;

    cout<<lie<<" ";

    //hang
    if(lie%2 == 1) if(a1loc%n!=0) hang=a1loc%n; else hang=n;
    else {
        if(a1loc%n==0) hang=1;
        else hang=n+1-a1loc%n;
    }

    cout<<hang<<endl;
    return 0;
}
