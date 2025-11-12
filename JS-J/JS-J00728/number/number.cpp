#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int num=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            num++;
            a[num]=s[i]-'0';
        }
    }
    sort(a+1,a+num+1);
    for(int i=num;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
