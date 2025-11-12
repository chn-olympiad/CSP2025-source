#include<bits/stdc++.h>
using namespace std;

void into()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
}

int main()
{
    into();
    string s,res; cin >>s;
    int a[s.size()];
    int x=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48 && s[i]<=57){
            a[x]=int(s[i])-48;
            x++;
        }
    }
    sort(a,a+x,greater<int>());
    for(int i=0;i<x;i++){
        cout <<a[i];
    }
    return 0;
}
