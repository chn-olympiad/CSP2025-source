#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<pair<string,string>> r(n);
    for(int i=0;i<n;i++) cin>>r[i].first>>r[i].second;
    for(int j=0;j<q;j++)
    {
        string s,t;
        cin>>s>>t;
        int cnt=0,lens=s.size();
        for(int pos=0;pos<=lens;pos++)
        {
            for(int i=0;i<n;i++)
            {
                const string &a1=r[i].first;
                const string &a2=r[i].second;
                int lenr=a1.size();
                if(pos+lenr>lens) continue;
                bool flag=true;
                for(int k=0;k<lenr;k++)
                {
                    if(s[pos+k]!=a1[k])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    string neww=s.substr(0,pos)+a2+s.substr(pos+lenr);
                    if(neww==t) cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}