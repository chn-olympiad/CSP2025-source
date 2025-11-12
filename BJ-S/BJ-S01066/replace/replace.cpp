#include<iostream>
#include<cstring>
using namespace std;
const int maxn=200005;
int n,q;
string s[maxn][5],s_f[maxn],s_t[maxn];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)//__________________________________________________________
    {
        string x,y;
        int l=0,r=x.length()-1;
        cin>>x>>y;
        for(int j=0;j<x.length();j++)
        {
            if(x[j]!=y[j])
            {
                l=j;
                break;
            }
            s_f[i]=s_f[i]+x[j];
        }
        for(int j=x.length()-1;j>=0;j--)
        {
            if(x[j]!=y[j])
            {
                r=j;
                break;
            }
        }
        for(int j=r+1;j<x.length();j++) s_t[i]=s_t[i]+x[j];
        for(int j=l;j<=r;j++)
        {
            s[i][1]=s[i][1]+x[j];
            s[i][2]=s[i][2]+y[j];
        }
    }
    for(int ii=1;ii<=q;ii++)//__________________________________________________________________
    {
        string x,y;
        cin>>x>>y;
        if(x.length()!=y.length())
        {
            cout<<0<<endl;
            continue;
        }
        int l=0,r=x.length()-1;
        for(int j=0;j<x.length();j++)
        {
            if(x[j]!=y[j])
            {
                l=j;
                break;
            }
        }
        for(int j=x.length()-1;j>=0;j--)
        {
            if(x[j]!=y[j])
            {
                r=j;
                break;
            }
        }
        string o,p;
        for(int i=l;i<=r;i++)
        {
            o=o+x[i];
            p=p+y[i];
        }
        int ans=0;bool flag=0;
        for(int i=1;i<=n;i++)//idui
        {
            if(o==s[i][1]&&p==s[i][2])
            {
                if(s_f[i].length()==0&&s_t[i].length()==0) ans++;
                else
                {
                    for(int j=l-s_f[i].length();j<l;j++)
                    {
                        if(flag==1) break;
                        if(x[j]!=s_f[i][j-l+s_f[i].length()])
                        {
                            flag=1;
                            break;
                        }
                    }
                    for(int j=r+1;j<=r+s_t[i].length();j++)
                    {
                        if(flag==1) break;
                        if(x[j]!=s_t[i][j-r-1])
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
