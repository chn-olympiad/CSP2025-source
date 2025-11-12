#include<bits/stdc++.h>
using namespace std;

int s[11];
string c;
bool f;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>c;
    for(int i=0;i<c.size();i++){
        if(isdigit(c[i])) s[c[i]-'0']++;
    }
    for(int i=9;i>=1;i--){
        for(int j=1;j<=s[i];j++){
            cout<<i;
            f=1;
        }
    }
    if(!f){
        cout<<"0\n";
    }
    else{
        for(int i=1;i<=s[0];i++) cout<<0;
        cout<<"\n";
    }
    return 0;
}   