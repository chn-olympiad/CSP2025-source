#include<bits/stdc++.h>
using namespace std;
string s,t;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(char i:s)
        if(isdigit(i))
            t+=i;
    sort(t.begin(),t.end(),greater<char>());
    cout<<t;
    return 0;
}
/*
g++ number.cpp -o number
number.exe

//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
*/