#include<iostream>
using namespace std;
int s[200010][3][3];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        for(int j=0;j<s1.size();j++)
        {
            if(s1[j]=='b')
            {
                s[i][1][1]=j;
                s[i][1][2]=s1.size()-j-1;
                break;
            }
        }
        for(int j=0;j<s2.size();j++)
        {
            if(s2[j]=='b')
            {
                s[i][2][1]=j;
                s[i][2][2]=s2.size()-j-1;
                break;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        string t1,t2;
        cin>>t1>>t2;
        int t11,t12,t21,t22;
        for(int i=0;i<t1.size();i++)
        {
            if(t1[i]=='b')
            {
                t11=i;
                t12=t1.size()-i-1;
                break;
            }
        }
        for(int i=0;i<t2.size();i++)
        {
            if(t2[i]=='b')
            {
                t21=i;
                t22=t2.size()-i-1;
                break;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i][1][1]<=t11&&s[i][1][2]<=t12&&s[i][2][1]<=t21&&s[i][2][2]<=t22&&(t21-t11)==(s[i][2][1]-s[i][1][1])&&(t22-t12)==(s[i][2][2]-s[i][1][2]))
            {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
