#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int cnt=0;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<int(s.size());i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[++cnt]=(s[i]-'0');
        }
    }
    sort(a+1,a+1+cnt,cmp);
    if(a[1]==0)
    {
        cout<<a[1];
        return 0;
    }
    for(int i=1;i<=cnt;i++)
    {
        cout<<a[i];
    }
    return 0;
}
