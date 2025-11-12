#include<bits/stdc++.h>
using namespace std;
string s;
int a[10010];
int xb;
int cddx(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i])) a[xb++]=s[i]-'0';
    }
    sort(a,a+xb,cddx);
    for(int i=0;i<xb;i++)
    {
        cout<<a[i];
    }
    return 0;
}
