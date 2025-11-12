#include<bits/stdc++.h>;
using namespace std;
int n,m,a[],b,c,d,e;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a;
        if(a[i]>a[i+1]){
            e=1;
            d=1;
            cout<<e<<d;
        }
        else{
            e=1;
            d=2;
            cout<<e<<d;
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i+2]>a[i+3]){
            e=2;
            d=2;
            cout<<e<<d;
        }
        else{
            e=2;
            d=1;
            cout<<e<<d;
        }
    }
    return 0;
}
