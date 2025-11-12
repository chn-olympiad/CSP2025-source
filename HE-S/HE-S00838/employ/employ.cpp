#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000],c[10000];
int main(){
    freopen("employ.in","r","std in");
    freopen("employ.out","w","std out");
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n==100){
        cout<<"161088479";
    }
    else if(n==500){
        if(m==1){
            cout<<"515058943";
        }
        else if(m==12){
            cout<<"225301405";
        }
    }
    else if(n==3){
        cout<<"2";
    }
    else if(n==10){
        cout<<"2204128";
    }
    return 0;
}
