#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int sl =s.size();
    int t[10]={0,0,0,0,0,0,0,0,0,0};
    while(sl--)
    {
        if(s[sl]=='0')
        {
            t[0]++;
        }
        if(s[sl]=='1')
        {
            t[1]++;
        }
        if(s[sl]=='2')
        {
            t[2]++;
        }
        if(s[sl]=='3')
        {
            t[3]++;
        }
        if(s[sl]=='4')
        {
            t[4]++;
        }
        if(s[sl]=='5')
        {
            t[5]++;
        }
        if(s[sl]=='6')
        {
            t[6]++;
        }
        if(s[sl]=='7')
        {
            t[7]++;
        }
        if(s[sl]=='8')
        {
            t[8]++;
        }
        if(s[sl]=='9')
        {
            t[9]++;
        }
    }
        for(int j=9;j>=0;j--)
        {
            while(t[j]--)
            {
                cout<<j;
            }
        }
    return 0;
}
