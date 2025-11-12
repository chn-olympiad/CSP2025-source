#include<bits/stdc++.h>
using namespace std;
int anst[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            anst[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=0;j<anst[i];j++)
        {
            cout<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
