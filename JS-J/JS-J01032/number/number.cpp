#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
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
    int cnt=0,n=s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[cnt]=(s[i]-'0');
            cnt++;
        }
    }
    sort(a,a+cnt,cmp);
    string ans="";
    for(int i=0;i<cnt;i++)
    {
        char x=a[i]+'0';
        ans+=x;
    }
    cout<<ans<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
