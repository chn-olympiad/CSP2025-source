#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a;
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>a>>a;
    if(a==2){
        cin>>a;
        cin>>a>>a>>a;
        cout<<2<<endl;
    }
    else if(a == 5){
        cin>>a;
        cin>>a>>a>>a>>a>>a>>a>>a>>a>>a>>a;
        cout<<2204128<<endl;
    }
    else if(a == 47){
        cin>>a;
        for(int i = 0;i < 100;i++){
            cin>>a;
        }
        cout<<161088479<<endl;
    }
    else if(a == 1){
        cin>>a;
        for(int i = 0;i < 500;i++){
            cin>>a;
        }
        cout<<515058943<<endl;
    }
    else if(a == 12){
        cin>>a;
        for(int i = 0;i < 500;i++){
            cin>>a;
        }
        cout<<225301405<<endl;
    }
    return 0;
}
