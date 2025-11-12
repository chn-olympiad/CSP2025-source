#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    map<string,string> trip;
    int n,q;
    cin>>n>>q;
    vector<string> str;
    for(int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;
        str.push_back(a);
        trip[a]=b;
    }
    for(int i=0;i<q;i++)
    {
        int ans=0;
        string a,b;
        cin>>a>>b;
        for(int j=0;j<str.size();j++)
        {
            int k,g;
            bool flag;
            if(str[j].size()>a.size())
            {
                continue;
            }
            for(k=0;k<a.size();k++)
            {
                flag=true;
                for(g=0;g<str[j].size();g++)
                {
                    if(k+g<a.size())
                    {
                        if(a[k+g]!=str[j][g])
                        {
                            flag=false;
                            break;
                        }
                    }

                }
                if(flag)
                {
                    break;
                }
            }
            if(flag)
            {
                string ews=a.substr(0,k);
                string bws=a.substr(k+g,a.size()-k-g);
                string news=ews+trip[str[j]]+bws;;
                if(news==b)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
