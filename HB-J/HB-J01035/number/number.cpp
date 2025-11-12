#include<bits/stdc++.h>
using namespace std;
int a[10];
string s;
int l,x;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(int i=0;i<10;i++) a[i]=0;
    for(int i=0;i<l;i++)
    {
        x=s[i];
        x-=48;
        if(x>=0 && x<=9)
            a[x]++;
    }
    for(int i=9;i>=0;i--)
    {
        while(a[i]!=0)
        {
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}
