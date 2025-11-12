#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int i,j,n,m;
   for(i=9;i>=0;i--)
    {
         for(j=0;j<=s.size();j++)
            if(s[j]-48==i)
            cout<<i;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
