#include<iostream>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    char a[n+10];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[sum++]=s[i];
        }
    }
    for(int i=0;i<sum;i++)
    {
        for(int j=0;j<sum-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=0;i<sum;i++)
    {
        cout<<a[i];
    }
    return 0;
}
