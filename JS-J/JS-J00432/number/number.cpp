#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000100]={-1};
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size(),tm=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'|s[i]=='8'||s[i]=='9')
        {
              tm++;
              a[tm]=s[i]-'0';
        }
    }
    sort(a,a+tm+1);
    for(int i=tm;i>=1;i--)
    {
        if(a[i]!=-1)
        {
            cout<<a[i];
        }
    }
    return 0;
}
