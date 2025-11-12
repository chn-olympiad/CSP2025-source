#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;s[i];i++){
        if(s[i]=='1') cnt=10*cnt+1;
        else if(s[i]=='2') cnt=10*cnt+2;
        else if(s[i]=='3') cnt=10*cnt+3;
        else if(s[i]=='4') cnt=10*cnt+4;
        else if(s[i]=='5') cnt=10*cnt+5;
        else if(s[i]=='6') cnt=10*cnt+6;
        else if(s[i]=='7') cnt=10*cnt+7;
        else if(s[i]=='8') cnt=10*cnt+8;
        else if(s[i]=='9') cnt=10*cnt+9;
        else if(s[i]=='0') cnt=10*cnt+0;
    }
    cout<<cnt;
    return 0;
}
