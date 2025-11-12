#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int a1[a.size()];
    int k=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<='9'&&a[i]>='0') a1[k++]=int(a[i]);
    }
    sort(a1,a1+k+1,greater<int>());
    for(int i=0;i<=k;i++)
    {
        if(a1[i]=='9') cout<<9;
        if(a1[i]=='8') cout<<8;
        if(a1[i]=='7') cout<<7;
        if(a1[i]=='6') cout<<6;
        if(a1[i]=='5') cout<<5;
        if(a1[i]=='4') cout<<4;
        if(a1[i]=='3') cout<<3;
        if(a1[i]=='2') cout<<2;
        if(a1[i]=='1') cout<<1;
        if(a1[i]=='0') cout<<0;
    }
    return 0;
}
