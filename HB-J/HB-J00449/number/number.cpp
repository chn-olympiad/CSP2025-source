#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number1.in","r",stdin);
    freopen("number1.out","w",stdout);
    //int n;
    //cin>>n;
    //cout<<n;
    string s;
    string ps="";
    cin>>s;
    int maxx=-1;
    int phs=0;
    for(int i=0;i<s.size();i++){
        if(int(s[i])>=97&&int(s[i])<=97+26){
            continue;
        }
        else{
            ps+=s[i];
        }
        phs=ps[i]-'0';
        maxx=max(maxx,phs);
    }
    cout<<maxx;
    return 0;
 }
