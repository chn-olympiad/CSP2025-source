#include <bits/stdc++.h>
using namespace std;
string s;
int i,j,a[1000005];
int w(int a,int b){
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(i=0;i<s.size();i++){
        if(isdigit(s[i])){
            a[j++]=s[i]-'0';
        }
    }
    sort(a,a+j,w);
    for(i=0;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
