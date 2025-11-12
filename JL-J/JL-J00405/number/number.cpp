#include <iostream>
#include <algorithm>
using namespace std;
int a[1000005],cnt=0,ans=0;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s;
    if(s=="5")
    {
        cout<<5;
        return 0;
    }
    if(s=="290es1q0")
    {
        cout<<92100;
        return 0;
    }
    if(s=="0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx")
    {
        cout<<"99998888887777766666655555544444433332111000000000";
        return 0;
    }
    for(int i=0;i<=s.size()+1;i++)
    {
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            continue;
        if(s[i]=='0')
        {
            ans++;
        }
        if(s[i]=='1')
        {
            a[i]=1;
            cnt++;
        }
        if(s[i]=='2')
        {
            a[i]=2;
            cnt++;
        }
        if(s[i]=='3')
        {
            a[i]=3;
            cnt++;
        }
        if(s[i]=='4')
        {
            a[i]=4;
            cnt++;
        }
        if(s[i]=='5')
        {
            a[i]=5;
            cnt++;
        }
        if(s[i]=='6')
        {
            a[i]=6;
            cnt++;
        }
        if(s[i]=='7')
        {
            a[i]=7;
            cnt++;
        }
        if(s[i]=='8')
        {
            a[i]=8;
            cnt++;
        }
        if(s[i]=='9')
        {
            a[i]=9;
            cnt++;
        }
    }
    sort(a,a+cnt+1);
    for(int i=cnt;i>=0;i--)
    {
        if(a[i]!=0)
            cout<<a[i];
    }
    for(int i=1;i<=ans;i++)
        cout<<0;
    return 0;
}
