#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000004];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    int m=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            m++;
            a[m]=s[i]-'0';
        }
    }
    sort(a+1,a+1+m);
    for(int i=m;i>=1;i--)
    {
        cout<<a[i];
    }

    return 0;
}
