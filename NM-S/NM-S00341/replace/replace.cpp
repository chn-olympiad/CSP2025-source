#include<bits/stdc++.h>
using namespace std;
int n,q;
long long sum=0;
string s[200200][3];
int a[200200][3];
bool fun(int l,int r,string c,string b)
{
    int lenc=c.size();
    int lenb=b.size();
    for(int i=0;i<l;i++)
    {
        if(c[i]!=b[i])
        {
            return false;
        }
    }
    if(lenc<=lenb)
    {
        for(int i=l+a[r][1];i<lenc;i++)
        {
            if(c[i]!=b[i+(lenb-lenc)])
            {
                return false;
            }
        }
    }
    else
    {
        for(int i=l+a[r][2];i<lenb;i++)
        {
            if(b[i]!=c[i+(lenc-lenb)])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    string s1,s2;
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        s[i][1]=s1;
        s[i][2]=s2;
        a[i][1]=s1.size();
        a[i][2]=s2.size();
    }
    string sq,ans;
    while(q--)
    {
        cin>>sq;
        cin>>ans;
        sum=0;
        int len=sq.size();
        for(int i=0;i<len;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(sq.substr(i,i+a[j][1])==s[j][1]&&ans.substr(i,i+a[j][2])==s[j][2]&&fun(i,j,sq,ans))
                {
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
