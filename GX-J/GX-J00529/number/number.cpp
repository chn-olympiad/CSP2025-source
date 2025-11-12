#include<bits/stdc++.h>
using namespace std;
int a[11];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s1;
    cin>>s1;
    for(int i=0;i<=s1.size();i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
        {
            a[s1[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        while(a[i]!=0)
        {
            cout<<i;
            a[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
