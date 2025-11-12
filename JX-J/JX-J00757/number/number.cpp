#include<bits/stdc++.h>
using namespace std;
string s;
int k,a[1000010];
bool f;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[++k]=s[i]-48;
        }
    }
    sort(a+1,a+1+k,cmp);
    for(int i=1;i<=k;i++)
    {
        if(a[1]==0)
        {
            cout<<a[1];
            break;
        }
        else{
            cout<<a[i];
        }
    }
    return 0;
}