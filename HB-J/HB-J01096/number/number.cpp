#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","r",stdout);
    string n;
    cin>>n;
    int x=0;
    for(int i=0;i<n.size();i++)
    {
        if(n[i]>='0' and n[i]<='9')
        {
            a[x]=n[i];
            x++;
        }
    }
    for(int i=0;i<x;i++)
    {
        int cnt=a[i]-'0';
        cout<<min(a[i+1]+'0',cnt);
        cnt=a[i+1]+'0';
    }
    return 0;
}
