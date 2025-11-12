#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
string s;
long long a[1000001];
long long k=0,l=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    for (long long i=0;i<=s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            a[k]=int(s[i]-'0');
            k++;
        }
    }
    sort(a,a+k,cmp);
    while(a[l]==0)
    {
        l++;
    }
    for (long long i=l;i<k;i++)
        cout<<a[i];

    return 0;
}
