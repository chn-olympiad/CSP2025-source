#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in",r,"stdin");
    freopen("number.out",w,"stdout");
    string s;
    cin>>s;
    long long k[s];
`   int a=0;
    for(int i=0;i<s.size;i++)
    {
        if((int)s[i]>65)
        {
            k[a]=s[i];
            a++;
        }
    }
    sort(k+s,k);
    for(int j=0;j<k;j++)
    {
        cout<<k[j];
    }
    return 0;
}