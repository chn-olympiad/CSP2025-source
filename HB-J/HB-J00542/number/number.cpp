#include<bits/stdc++.h>
using namespace std;
int caso=0;
char a[1000010];
string s,ans;
bool cmp(int a1,int a2)
{
    return a1>a2;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.size();i++)
        if(s[i]>='0' and s[i]<='9')
        {
            a[caso]=s[i];
            caso++;
        }
    sort(a,a+caso,cmp);
    for(int i=0;i<caso;i++)
        ans+=a[i];
    cout<<ans;
    return 0;
}
