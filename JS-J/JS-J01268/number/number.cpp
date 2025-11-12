#include<bits/stdc++.h>
using namespace std;
string s;
int n[10],a;
bool q;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int i;
    do{
        if(s[i]=='9') n[9]++;
        else if(s[i]=='8') n[8]++;
        else if(s[i]=='7') n[7]++;
        else if(s[i]=='6') n[6]++;
        else if(s[i]=='5') n[5]++;
        else if(s[i]=='4') n[4]++;
        else if(s[i]=='3') n[3]++;
        else if(s[i]=='2') n[2]++;
        else if(s[i]=='1') n[1]++;
        else if(s[i]=='0') n[0]++;
        i++;
    }while(s[i]);
    while(n[9]){
        n[9]--;
        a=a*10+9;
    }while(n[8]){
        n[8]--;
        a=a*10+8;
    }while(n[7]){
        n[7]--;
        a=a*10+7;
    }while(n[6]){
        n[6]--;
        a=a*10+6;
    }while(n[5]){
        n[5]--;
        a=a*10+5;
    }while(n[4]){
        n[4]--;
        a=a*10+4;
    }while(n[3]){
        n[3]--;
        a=a*10+3;
    }while(n[2]){
        n[2]--;
        a=a*10+2;
    }while(n[1]){
        n[1]--;
        a=a*10+1;
    }while(n[0]){
        n[0]--;
        a=a*10;
    }
    cout<<a;
    return 0;
}
