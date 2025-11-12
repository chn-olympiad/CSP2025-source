#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
vector<string> s1,s2;
string t1,t2;
vector<int> l;
bool ch(int x,int j,int len)
{
    if(l[x]>(int)(t1.size()-j)) return 0;
    for(int i=0;i<l[x];i++)
    {
        if(s1[x][i]!=t1[i+j]) return 0;
    }
    return 1;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    string str1,str2;
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>str1>>str2;
        s1.push_back(str1);
        s2.push_back(str2);
        t=str1.size();
        l.push_back(t);
    }
    string tmp;
    int len;
    while(q--)
    {
        int ans=0;
        cin>>t1>>t2;
        t=t1.size();
        if(t1.size()!=t2.size())
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<t;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ch(j,i,t))
                {
                    tmp=t1;
                    for(int k=0;k<l[j];k++)
                    {
                        tmp[k+j]=s2[j][k];
                    }
                    if(tmp==t2) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
