#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long sum=0;
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            sum++;
        }
    }
    char a[sum];long long k=0;
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            a[k]=s[i];
            k++;
        }
    }
    sort(a,a+sum);
    for(long long i=sum-1;i>=0;i--)
    {
        cout<<a[i];
    }
    return 0;
}


