#include<bits/stdc++.h>
using namespace std;
int a[1000086];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int j=1;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        int t=s[i]-'0';
        if(t>=0&&t<=9)
        {
            a[j]=t;
            j++;
        }
    }
    sort(a+1,a+j);
    for(int i=j-1;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
