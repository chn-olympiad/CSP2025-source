#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int cnt=1,ans=0;
    string s;
    cin>>s;
    if(s.size()==1)
    {
        cout<<s;
        return 0;
    }
    for(int i=0;i<=s.size()-1;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[cnt]=s[i]-'0';
            if(i==s.size()-1)
            {
                break;
            }
            else
            {
                cnt++;
            }
        }
    }
    int n=a[cnt];
    for(int i=0;i<=s.size()-1;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            ans++;
        }
    }
    if(cnt-1==ans)
    {
        sort(a+1,a+cnt+1,cmp);
    }
    else
    {
        sort(a+1,a+ans+1,cmp);
    }
    for(int i=1;i<=ans;i++)
    {
        cout<<a[i];
    }
    return 0;
}
