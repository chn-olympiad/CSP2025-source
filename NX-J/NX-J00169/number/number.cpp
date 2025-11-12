#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    string sum;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            sum+=s[i];
        }
    }
    for(int i=0;i<sum.size();i++)
    {
       for(int j=i+1;j<sum.size();j++)
        {
            if(sum[i]<sum[j])
            {
               swap(sum[i],sum[j]);
            }
        }
    }
    cout<<sum;
    return 0;
}
