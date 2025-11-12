#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size();
    int sum=1;
    for(int i=0;i<l;i++)
    {
        if(int(s[i])>=48&&int(s[i])<=57)
        {
            a[sum]=int(s[i])-48;
            sum++;
        }
    }
    sort(a+1,a+sum+1);
    for(int i=sum;i>1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
