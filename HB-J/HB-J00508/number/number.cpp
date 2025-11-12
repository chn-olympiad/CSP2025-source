#include<bits/stdc++.h>
using namespace std;
int num[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++)
        if(a[i]-'0'>=0 and a[i]-'0'<=9)
            num[a[i]-'0']++;
    for(int j=9;j>=0;j--)
    {
        for(int i=0;i<num[j];i++)
            cout<<j;
    }
    return 0;
}
