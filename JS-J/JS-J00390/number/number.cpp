#include <bits/stdc++.h>
using namespace std;
string s,num="";
bool cmp(char a,char b){return a>b;}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(auto i:s){
        if(i>='0' && i<='9') num+=i;
    }
    sort(num.begin(),num.end(),cmp);
    cout<<num;
    return 0;
}
