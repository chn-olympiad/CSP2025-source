#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int b=0;
    for(int i=0;i<s.length();i++)
    {
        for(int j=i+1;j<=s.length();j++)
        {
            if(s[i]<=s[j])

            {
                b=s[i];
                s[i]=s[j];
                s[j]=b;

            }
            else{
                continue;
            }
        }
        cout<<s[i];
    }


    return 0;
}
