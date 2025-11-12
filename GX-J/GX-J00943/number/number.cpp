#include <bits/stdc++.h>
using namespace std;
string s;
int x,n;
string a[101];
int main(){
freopen("number1.in","r",stdin);
freopen("number1.out","w",stdout);
cin>>s;
n=s.length();
for(int i=0;i<n;i++){
    if(s[i]>='a'&&s[i]<='z'){

    }
    else{
        a[x]=s[i];
        x++;
    }
}
sort(a,a+n);
for(int i=0;i<x;i++){
    cout<<a[i];
}
return 0;
}
