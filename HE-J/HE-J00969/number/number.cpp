#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //
    char s[1001];
    int a[10001];
    int sum=0,l;
    cin>>s;
    l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i]=s[i];
            a[i]-=48;
            sum++;
        }
    }
    for(int i=0;i<=sum;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(a[i]>=a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<sum;i++)
    {
        cout<<a[i];
    }
    return 0;
}
