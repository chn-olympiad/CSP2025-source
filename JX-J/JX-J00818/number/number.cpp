#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int s[1000001];
    int c=1;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(int(a[i])>=48 and int(a[i])<=57)
        {
            s[c]=int(a[i]);
            c++;
        }
    }
    sort(s+1,s+c+1);
    for(int i=c;i>=1;i--)
    {
        cout<<char(s[i]);
    }
    return 0;
}
