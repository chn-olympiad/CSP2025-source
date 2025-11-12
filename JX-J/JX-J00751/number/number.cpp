#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],ans=0,i=1;
int main(){
    freopen("seat.in","r","stdin");
    freopen("seat.out","w","stdout");
    getline(cin,s);
    while(i<s.size()){
        a[i]=s[i]-'0';
        ans=ans+1;
        i++;
    }
    sort(a,a+ans);
    for(int i=ans;i>=0;i++)cout<<a[i]<<' ';
    freclose("seat.in","r","stdin");
    freclose("seat.out","w","stdout");
    return 0;
    }

