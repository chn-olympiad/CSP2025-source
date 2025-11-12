#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool lmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int id=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[++id]=s[i]-'0';
        }
    }
    sort(a+1,a+1+id,lmp);
    for(int i=1;i<=id;i++)
    {
        cout<<a[i];
    }
    return 0;
}
