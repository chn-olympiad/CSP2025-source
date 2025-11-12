#include<bits/stdc++.h>
using namespace std;
int a[60];
int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
            int shu=s[i]-48;
            //cout<<shu;
            a[shu+1]++;
        }
    }
    for(int i=10;i>=1;i--)
    {
        if(a[i]>0)
        {
            for(int j=1;j<=a[i];j++)
            {
                cout<<i-1;
            }
        }
    }
    return 0;
}
//jia you!