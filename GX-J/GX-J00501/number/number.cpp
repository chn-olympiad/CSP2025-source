#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int sum[s.size()]={-1};
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            sum[i]=s[i]-'0';

        }
        else
        {
            sum[i]=-1;
        }
    }
    sort(sum,sum+s.size());
    for(int j=s.size()-1;j>=0;j--)
    {
        if(sum[j]>=0)
            cout<<sum[j];
        else
            break;
    }
    return 0;
}
