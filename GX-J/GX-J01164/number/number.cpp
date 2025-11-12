#include<bits/c++.h>
using namespce std;
int a1[1000005],maxx;
int main()
{
    string s;
    cin>>s;
    for(int i = 0;i<=s.lenghth()-1;i++)
    {
        if(s[i]-'0' >= '1' && s[i] - '0' <= '9')
        {
            a1[i] = s[i] - '0';
        }
    }
    for(int i = 0;i<=s.lenghth();i++)
    {
        for(int j = 0;j<=s.lenghth()-i+1;j++)
        {
            if(a1[j] >a1[j+1])
            {
                int p = a1[j];
                a1[j] = a1[j+1];
                a1[j+i] = p;
             }
        }
    }
    maxx = a1[0] *100 + a1[0] *10 + a1[2];
    cout<<maxx;
    return 0 ;
}
