#include<bits/stdc++.h>
using namespace std;
string s;
string a[19];
int b[19];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int f1=0,f2=0,f3=0,f4=0,f5=0,f6=0,f7=0,f8=0,f9=0,f0=0;
    for(int i=0;i<s.length()+1;i++){
        if(s[i]=='1'){
            a[1][f1]='1';
            f1++;
            b[1]++;
        }
        if(s[i]=='2'){
            a[2][f2]='2';
            f2++;
            b[2]++;
        }
        if(s[i]=='3'){
            a[3][f3]='3';
            f3++;
            b[3]++;
        }
        if(s[i]=='4'){
            a[4][f4]='4';
            f4++;
            b[4]++;
        }
        if(s[i]=='5'){
            a[5][f5]='5';
            f5++;
            b[5]++;
        }
        if(s[i]=='6'){
            a[6][f6]='6';
            f6++;
            b[6]++;
        }
        if(s[i]=='7'){
            a[7][f7]='7';
            f7++;
            b[7]++;
        }
        if(s[i]=='8'){
            a[8][f8]='8';
            f8++;
            b[8]++;
        }
        if(s[i]=='9'){
            a[9][f9]='9';
            f9++;
            b[9]++;
        }
        if(s[i]=='0'){
            a[0][f0]='0';
            f0++;
            b[0]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<b[i];j++){
            cout<<a[i][j];
        }
    }
    return 0;
    }
