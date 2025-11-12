#include<bits/stdc++.h>
using namespace std;
int t[15];
string m="";
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    for(int i=0;i<n.size();i++){
        if(n[i]>='0'&&n[i]<='9')t[n[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<t[i];j++){
            m+=(char)(i+'0');
        }
    }
    cout<<m;
    return 0;
}
