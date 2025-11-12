#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            n0++;
        }else if(s[i]=='1'){
            n1++;
        }else if(s[i]=='2'){
            n2++;
        }else if(s[i]=='3'){
            n3++;
        }else if(s[i]=='4'){
            n4++;
        }else if(s[i]=='5'){
            n5++;
        }else if(s[i]=='6'){
            n6++;
        }else if(s[i]=='7'){
            n7++;
        }else if(s[i]=='8'){
            n8++;
        }else if(s[i]=='9'){
            n9++;
        }
    }
    for(int i=1;i<=n9;i++){
        cout<<"9";
    }
    for(int i=1;i<=n8;i++){
        cout<<"8";
    }
    for(int i=1;i<=n7;i++){
        cout<<"7";
    }
    for(int i=1;i<=n6;i++){
        cout<<"6";
    }
    for(int i=1;i<=n5;i++){
        cout<<"5";
    }
    for(int i=1;i<=n4;i++){
        cout<<"4";
    }
    for(int i=1;i<=n3;i++){
        cout<<"3";
    }
    for(int i=1;i<=n2;i++){
        cout<<"2";
    }
    for(int i=1;i<=n1;i++){
        cout<<"1";
    }
    for(int i=1;i<=n0;i++){
        cout<<"0";
    }
    return 0;
}
