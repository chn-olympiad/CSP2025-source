#include<bits/stdc++.h>
using namespace std;
string s,t;
bool cmp(char a,char b){return a>b;}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(auto c:s)
        if(c>='0'&&c<='9')
            t+=c;
    sort(t.begin(),t.end(),cmp);
    cout<<t;
    return 0;
}
