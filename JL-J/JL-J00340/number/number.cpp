#include<bits/stdc++.h>
using namespace std;
string s;
long long sum=0,a[10001];
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin>>s;
    for(int i=1;i<=s.size();i++)
    {
        if(i<='9'&&i>='0')
        {
            sum++;
        }
    }
    for(int j=1;j<=s.size();j++)
    {
        char p=s.size();
        if(p<='9' && p>='0')
        {
            a[j]=s.size();
        }
    }
    for(int i=1;i<=s.size();i++)
    {
        cout<<a[i];
    }
    cout<<endl<<sum;
    return 0;
}
