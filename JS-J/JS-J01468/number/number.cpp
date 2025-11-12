#include<bits/stdc++.h>
#include<string>
using namespace std;
int i=1,ans[1000001];
string s;
char a;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    //cout<<s;
    for(int j=0;j<s.length();j++)
    {
        if(s[j]>='0'&&s[j]<='9')
        {
            a=s[j];
            ans[i]=(a-'0');
            i++;
        }
    }
    int qwe;
    //cout<<i<<endl;
    i--;
    for(int j=i;j>1;j--)
    {
        for(int x=i-1;x>=1;x--)
        {
            if(ans[x]<ans[x+1])
            {
                qwe=ans[x];
                ans[x]=ans[x+1];
                ans[x+1]=qwe;
            }
        }
    }
    for(int j=1;j<=i;j++)
    {
        cout<<ans[j];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
