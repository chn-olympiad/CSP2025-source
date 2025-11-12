#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> mp;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string a,b;cin>>a>>b;
        mp[a]=b;
    }
    while(q--)
    {
        int cnt=0;
        string ta,tb;
        cin>>ta>>tb;
        for(int i=0;i<=ta.size()-1;i++)
        {
            for(int j=1;j<=ta.size();j++)
            {
                if(i+j>ta.size())break;
                string x,y,z;
                for(int k=0;k<=i-1;k++)
                {
                    x+=ta[k];
                }
                for(int k=i;k<=i+j-1;k++)
                {
                    y+=ta[k];
                }
                for(int k=i+j;k<ta.size();k++)
                {
                    z+=ta[k];
                }
                if(mp.count(y)==1)
                {
                    y=mp[y];
                }
                if(x+y+z==tb)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
