#include<bits/stdc++.h>
using namespace std;
int n,q,a1[100005],h,ans,x1,x2;
string s1[100005][2],s2,s3;
void dfs(int now)
{
    if(now>x1)
    {
        return;
    }
    int i,j;
    int y=0;
    for(i=1;i<=n;i++)
    {
        if(s1[i][0][0]==s2[now]&&h-now>=a1[i]&&s1[i][1][0]==s3[now])
        {
            y=0;
            for(j=0;j<a1[i];j++)
            {
                if(s1[i][0][j]!=s2[now+j]||s1[i][1][j]!=s3[now+j])
                {
                    y=1;
                    break;
                }
            }
            if(y==0)
            {
                if(now+a1[i]>=x2)
                {
                    ans++;
                }
            }
        }
    }
    dfs(now+1);
    return;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>s1[i][0]>>s1[i][1];
        a1[i]=s1[i][0].size();
    }
    for(i=0;i<q;)
    {
        ans=0;
        cin>>s2;
        cin>>s3;
        if(s2.size()!=s3.size())
        {
            cout<<0<<endl;
            i++;
            continue;
        }
        h=s2.size();
        x1=0;
        for(i=0;i<h;i++)
        {
            if(s2[i]!=s3[i])
            {
                break;
            }
            x1++;
        }
        x2=h-1;
        for(i=h-1;i>=0;i--)
        {
            if(s2[i]!=s3[i])
            {
                break;
            }
            x2--;
        }
        dfs(0);
        cout<<ans<<endl;
        i++;
        if(i>=q)
        {
            return 0;
        }
    }
    return 0;
}


