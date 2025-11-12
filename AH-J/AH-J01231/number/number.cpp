#include<bits/stdc++.h>
using namespace std;
char s1;
int s2[11],i,j,t;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>s1)
    {
        if(s1>='0'&&s1<='9')
            s2[s1-'0']++;
    }
    for(i=9;i>=0;i--)
    {
        for(j=1;j<=s2[i];j++)
        {
            if(i!=0)
            {
                cout<<i;
                t=1;
            }
            if(i==0)
            {
                if(t==1)
                    cout<<i;
            }
        }
    }
    if(t==0)
        cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
