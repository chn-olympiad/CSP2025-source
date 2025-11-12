#include<bits/stdc++.h>
using namespace std;
int a[10],len,i=10;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    while(len){
        len--;
        if(s[len]=='0') a[0]++;
        else if(s[len]=='1') a[1]++;
        else if(s[len]=='2') a[2]++;
        else if(s[len]=='3') a[3]++;
        else if(s[len]=='4') a[4]++;
        else if(s[len]=='5') a[5]++;
        else if(s[len]=='6') a[6]++;
        else if(s[len]=='7') a[7]++;
        else if(s[len]=='8') a[8]++;
        else if(s[len]=='9') a[9]++;
    }while(i){
        i--;
        while(a[i]){
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}
