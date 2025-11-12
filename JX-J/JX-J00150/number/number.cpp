#include<bits/stdc++.h>
using namespace std;
int ling,yi,er,san,si,wu,liu,qi,ba,jiu;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]==48){
            ling++;
        }
        if(s[i]==49){
            yi++;
        }
        if(s[i]==50){
            er++;
        }
        if(s[i]==51){
            san++;
        }
        if(s[i]==52){
            si++;
        }
        if(s[i]==53){
            wu++;
        }
        if(s[i]==54){
            liu++;
        }
        if(s[i]==55){
            qi++;
        }
        if(s[i]==56){
            ba++;
        }
        if(s[i]==57){
            jiu++;
        }
    }
    for(int i=1;i<=jiu;i++){
        cout<<"9";
    }
    for(int i=1;i<=ba;i++){
        cout<<"8";
    }
    for(int i=1;i<=qi;i++){
        cout<<"7";
    }
    for(int i=1;i<=liu;i++){
        cout<<"6";
    }
    for(int i=1;i<=wu;i++){
        cout<<"5";
    }
    for(int i=1;i<=si;i++){
        cout<<"4";
    }
    for(int i=1;i<=san;i++){
        cout<<"3";
    }
    for(int i=1;i<=er;i++){
        cout<<"2";
    }
    for(int i=1;i<=yi;i++){
        cout<<"1";
    }
    for(int i=1;i<=ling;i++){
        cout<<"0";
    }
    return 0;
}
