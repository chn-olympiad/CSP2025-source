#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000];
bool f;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
    }

    for(int i=9; i>=0; i--)
    {
        if(a[i]==0)continue;
        if(i==0&&f==0)
        {
            cout<<0;
            break;
        }
        f=1;
        while(a[i])cout<<i,a[i]--;
    }






    return 0;
}
