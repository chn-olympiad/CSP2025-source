#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
unsigned long long a[100001],n,sum;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i]=s[i]-'0';
            n=n+1;
        }
    }
    sort(a,a+s.size(),cmp);
    for(int i=0;i<n;i++)
    {

        cout<<a[i];
    }
    return 0;
}
