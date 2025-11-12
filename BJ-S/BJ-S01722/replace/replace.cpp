#include<bits/stdc++.h>
using namespace std;
struct se
{
    string s1,s2;
};
int same(string a,string b)
{
    int c=a.size();
    for(int i=0;i<c;i++)
    {
        if(a[i]!=b[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    se s[n],t[q];
    for(int i=0;i<n;i++)
    {
        cin>>s[i].s1>>s[i].s2;
    }
    for(int i=0;i<q;i++)
    {
        int ans=0;
        cin>>t[i].s1>>t[i].s2;
        if(int((t[i].s1).size())!=int((t[i].s2).size()))
        {
            cout<<"0\n";
            continue;
        }
        int left,right;
        for(int j=0;j<int((t[i].s1).size());j++)
        {
            if(t[i].s1[j]!=t[i].s2[j])
            {
                left=j;
                break;
            }
        }
        for(int j=int((t[i].s1).size())-1;j>=0;j--)
        {
            if(t[i].s1[j]!=t[i].s2[j])
            {
                right=j;
                break;
            }
        }
        for(int j=0;j<n;j++)
        {
            if(int((s[j].s1).size())>=right-left+1)
            {
                for(int k=0;k<int((t[i].s1).size()-(s[j].s1).size())+1;k++)
                {
                    bool cou=true;
                    for(int l=k;l<k+int((s[j].s1).size());l++)
                    {
                        if(t[i].s1[l]!=s[j].s1[l-k])
                        {
                            cou=false;
                            break;
                        }
                    }
                    if(cou)
                    {
                        char hel[int((s[j].s1).size())];
                        for(int l=k;l<k+int((s[j].s1).size());l++)
                        {
                            hel[l-k]=t[i].s1[l];
                        }
                        for(int l=k;l<k+int((s[j].s1).size());l++)
                        {
                            t[i].s1[l]=s[j].s2[l-k];
                        }
                        if(same(t[i].s1,t[i].s2))
                        {
                            ans++;
                        }
                        for(int l=k;l<k+int((s[j].s1).size());l++)
                        {
                            t[i].s1[l]=hel[l-k];
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}