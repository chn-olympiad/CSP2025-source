#include<bits/stdc++.h>
using namespace std;
string s1[200010],s2[200010];
vector<int>v;
map<int,int>m;
map<string,int>m1,m2;
int hou[5000010],qian[5000010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i = 1;i<=a;i++)
    {
        cin>>s1[i]>>s2[i];
        if(m[s1[i].size()]==0)
        v.push_back(s1[i].size());
        m[s1[i].size()]=1;
        m1[s1[i]]=1;
        m2[s2[i]]=1;
    }
    sort(v.begin(),v.end());
    while(b--)
    {
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
        {
            cout <<"0"<<endl;
            continue;
        }
        for(int i = t1.size()-1;i>=0;i--)
        {
            if(hou[i+1]==1)
            {
                hou[i]=1;
            }
            else
            {
                if(t1[i]==t2[i])
                    hou[i]=0;
                else
                    hou[i]=1;
            }
        }
        if(t1[0]==t2[0])
            qian[0]=0;
        else
            qian[0]=1;
        for(int i = 1;i<t1.size();i++)
        {
            if(qian[i-1]==1)
            qian[i]=1;
            else
                if(t1[i]==t2[i])
                qian[i]=0;
                else
                qian[i]=1;
        }
        int ans = 0;
        for(int i=  0;i<t1.size();i++)
        {
            for(int j = 0;j<v.size();j++)
            {
                int k = v[j];
                if(i+k-1>=t1.size())
                    break;
                if(m1[t1.substr(i,k)]==1&&m2[t2.substr(i,k)]==1&&hou[i+k]==0&&(i==0||qian[i-1]==0))
                {
                    ans++;
                }
            }
        }
        cout <<ans<<endl;
    }
    return 0;
}
