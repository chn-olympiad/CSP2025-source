#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n[10086];
bool stp(int a,int b){
if(a>=b){
    return true;
}
if(b>a){
    return false;
}
}
int main(){
    freopen('number.in',"r",'std.in');
    freopen('number.out',"w",'std.out');
    string s;
    cin>>s;
    for(int i=0;i<=s.length():i++){
        if(s[i]=='1'){
            n[i]=1;
        }
        if(s[i]=='2'){
            n[i]=2;
        }
        if(s[i]=='3'){
            n[i]=3;
        }
        if(s[i]=='4')
        {
            n[i]=4;
        }
        if(s[i]=='5'){
            n[i]=5;
        }
        if(s[i]=='6'){
            n[i]=6;
        }
        if(s[i]=='7'){
            n[i]=7;
        }
        if(s[i]=='8'){
            n[i]=8;
        }
        if(s[i]=='9'){
            n[i]=9;
        }
        if(s[i]=='0'){
            n[i]=0;
        }
    }
    sort(1,n+1,stp);
    cout<<n[0]*100+n[1]*10+n[2];
}
