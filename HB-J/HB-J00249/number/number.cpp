#include<bits/stdc++.h>
using namespace std;
string s;
int a[100001];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int t=s.size();
    int k=0;
    for(int x=0;x<t;x++)
    {
        if(s[x]>='0'&&s[x]<='9')
        {
            a[k]=s[x]-'0';
            k++;
        }
    }
    for(int x=0;x<k;x++)
    {
        for(int y=x+1;y<k;y++)
        {
            if(a[x]<a[y]) swap(a[x],a[y]);
        }
    }
    for(int x=0;x<k;x++)
    {
        cout<<a[x];
    }
    return 0;
}
