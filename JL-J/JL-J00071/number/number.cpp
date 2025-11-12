#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]<=57&&s[i]>=48)
        {
            a[i+1]=s[i]-'0';
            cnt++;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        int max=i;
        for(int j=i+1;j<=cnt;j++)
        {
            if(a[j]>a[max])
            {
                a[max]=a[j];
            }
            swap(a[i],a[j]);
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        cout<<a[i];
    }
    return 0;
}
