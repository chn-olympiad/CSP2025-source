#include<bits/stdc++.h>
using namespace std;
string a,b;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(char c:a){
        if(c>='0'&&c<='9') b+=c;
    }
    sort(b.begin(),b.end(),cmp);
    cout<<b;
    return 0;
}
