#include<bits/stdc++.h>
using namespace std;
int n[1000005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size(),c=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
            c++;
            n[c]=s[i]-48;
        }
    }
    sort(n+1,n+c+1,cmp);
    for(int i=1;i<=c;i++)cout<<n[i];
    return 0;
}
