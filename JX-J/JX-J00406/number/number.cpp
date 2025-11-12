#include<bits/stdc++.h>
using namespace std;
string s;
long long r[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<1005;i++){
        if(s[i]=='1'){
            r[1]++;
        }
        if(s[i]=='2'){
            r[2]++;
        }
        if(s[i]=='3'){
            r[3]++;
        }
        if(s[i]=='4'){
            r[4]++;
        }
        if(s[i]=='5'){
            r[5]++;
        }
        if(s[i]=='6'){
            r[6]++;
        }
        if(s[i]=='7'){
            r[7]++;
        }
        if(s[i]=='8'){
            r[8]++;
        }
        if(s[i]=='9'){
            r[9]++;
        }
        if(s[i]=='0'){
            r[0]++;
        }
    }
    for(int i=0;i<r[9];i++){
        cout<<'9';
    }
    for(int i=0;i<r[8];i++){
        cout<<'8';
    }
    for(int i=0;i<r[7];i++){
        cout<<'7';
    }
    for(int i=0;i<r[6];i++){
        cout<<'6';
    }
    for(int i=0;i<r[5];i++){
        cout<<'5';
    }
    for(int i=0;i<r[4];i++){
        cout<<'4';
    }
    for(int i=0;i<r[3];i++){
        cout<<'3';
    }
    for(int i=0;i<r[2];i++){
        cout<<'2';
    }
    for(int i=0;i<r[1];i++){
        cout<<'1';
    }
    for(int i=0;i<r[0];i++){
        cout<<'0';
    }

    return 0;
}

