#include<bits/stdc++.h>
using namespace std;
string s;
string a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(char c:s){
        if('0'<=c&&c<='9') a+=c;
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    cout<<a<<endl;
    return 0;
}
