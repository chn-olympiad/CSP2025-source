#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000],n;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;s[i]!=' ';i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i]=s[i]-'0';
        }
    }
    sort(a,a+n);
    if(a[0]==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
