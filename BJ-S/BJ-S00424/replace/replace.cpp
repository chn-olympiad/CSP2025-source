#include <iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int n,m;
map<string,vector<string> > mp;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        mp[s1].push_back(s2);
    }
    for(int i=1;i<=m;i++)
    {
        int ans=0;
        string s1,s2;
        cin>>s1>>s2;
        int l=0,r=s1.length()-1;

        while(s1[l]==s2[l])l++;
        while(s1[r]==s2[r])r--;


        for(int k=0;k<=l;k++)
        {
            for(int p=r;p<s1.length();p++){
                vector<string> t(mp[s1.substr(k,p-k+1)]);
                for(int j=0;j<t.size();j++)
                    if(s2.substr(k,p-k+1)==t[j])
                        ans++;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
