#include<bits/stdc++.h>
using namespace std;
string a;
char b;
int w;
int s[10]={0,1,2,3,4,5,6,7,8,9};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,a);
    b=s[i];
    w=b-'0';
    for(int i=0;i<a.length();i++)
    {
        for(int i=9;i>=0;i--)
        {
            for(int j=1;j<=s[i];j++)cout<<j;
        }
    }
    return 0;
}
