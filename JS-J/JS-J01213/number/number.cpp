#include<bits/stdc++.h>
using namespace std;
int a[1000021];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    int j=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            j++;
            a[j]=int(s[i]-48);
        }
    }
    sort(a+1,a+1+j);
    for(int i=j;i>=1;i--)
    {
        cout<<a[i];
    }
    cout<<'\n';
    return 0;
}