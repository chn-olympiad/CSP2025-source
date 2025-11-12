#include<bits/stdc++.h>
using namespace std;
string s,b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long a=0;
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){

        }
        else{
                s[i]=b[a];
        }
    }
    sort(s.begin(),s.end());
    long long m=s.size();
    if(s[m]=='0'){
        cout<<'0';
    }
    else{
        for(int i=0;i<=s.size();i++){
            cout<<s[m-a];
            a++;
        }}
    return 0;
}
