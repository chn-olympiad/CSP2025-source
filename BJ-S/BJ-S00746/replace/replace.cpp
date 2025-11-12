#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int x;
    char c1,c2;
};
vector<node> ch[5000006];
int jw[5000006];
int cnt=0;
bool finds(string s1,string s2,int i,int r,int x)
{
    if(i>r)
    {
        if(jw[x])
        return true;
        return false;
    }
    bool ans=false;
    for(node y:ch[x])
    {
        if(y.c1==s1[i]&&y.c2==s2[i])
        {
            ans=finds(s1,s2,i+1,r,y.x);
            break;
        }
    }
    return ans;
}
void adds(string s1,string s2,int i,int x)
{
    for(node y:ch[x])
    {
        if(y.c1==s1[i]&&y.c2==s2[i])
        {
            adds(s1,s2,i+1,y.x);
            return;
        }
    }
    for(;i<s1.size();i++)
    {
        ch[x].push_back({++cnt,s1[i],s2[i]});
        x=cnt;
    }
    jw[x]=1;
}
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
        adds(s1,s2,0,0);
    }
    for(int i=1;i<=q;i++)
    {
        string t1,t2;
        cin>>t1>>t2;
        int maxl,minr;
        for(int i=0;i<t1.size();i++)
        {
            if(t1[i]!=t2[i])
            {
                maxl=i;
                break;
            }
        }
        for(int i=t1.size()-1;i>=0;i--)
        {
            if(t1[i]!=t2[i])
            {
                minr=i;
                break;
            }
        }
        int ans=0;
        for(int l=0;l<=maxl;l++)
        {
            for(int r=minr;r<t1.size();r++)
            {
                if(finds(t1,t2,l,r,0))
                {
                    ans+=1;
                    //cout<<l<<" "<<r<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}