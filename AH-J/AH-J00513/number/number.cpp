#include<bits/stdc++.h>
using namespace std;
long long n,m,xb;
char t[50];
string s;
long long slen;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    slen=s.size();
    for(long long i=0;i<=slen;i++){
        if(s[i]=='0'||(s[i]>='1'&&s[i]<='9')){
            t[s[i]-'0']++;
        }
    }
    for(long long i=0;i<t[9];i++){
        cout<<"9";
    }
    for(long long i=0;i<t[8];i++){
        cout<<"8";
    }
    for(long long i=0;i<t[7];i++){
        cout<<"7";
    }
    for(long long i=0;i<t[6];i++){
        cout<<"6";
    }
    for(long long i=0;i<t[5];i++){
        cout<<"5";
    }
    for(long long i=0;i<t[4];i++){
        cout<<"4";
    }
    for(long long i=0;i<t[3];i++){
        cout<<"3";
    }
    for(long long i=0;i<t[2];i++){
        cout<<"2";
    }
    for(long long i=0;i<t[1];i++){
        cout<<"1";
    }
    for(long long i=0;i<t[0];i++){
        cout<<"0";
    }
    return 0;
}



