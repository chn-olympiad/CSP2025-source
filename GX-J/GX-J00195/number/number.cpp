#include<bits/stdc++.h>
using namespace std;
int a[11]={0},b[11]={0};
int main()
{
    freopen("r","number.in",stdin);
    freopen("w","number.out",stdout);
    (string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' and s[i]<='9')
        {
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i<=0;i++)
    {
        if(a[i]!=0)
        {
            for(int j=1;j<=a[i];j++)
            {
                cout<<i;
            }
        }
    }
    return 0;
}
