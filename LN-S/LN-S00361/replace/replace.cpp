#include<bits/stdc++.h>
using namespace std;
string s1[100010],s2[100010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;i++)
    {
        string space ;
        cin>>s1[i]>>s2[i];
        //cout<<s1[i]<<endl<<s2[i]<<endl;
    }
    for(int i = 1;i<=q;i++)
    {
        string a,b;
        cin>>a>>b;
        //cout<<a<<endl<<b<<endl;
        int ans=0;
        for(int j = 1;j<=n;j++)
        {
            int k = 0;
            int cnt=0;
            bool flag=false;
            while(k<(int)a.size())
            {
                //cout<<k<<" ";
                int len=0;
                int x = k;
                while(a[x]==s1[j][len]&&s2[j][len]==b[x]&&len<(int)s1[i].size()&&!flag)
                {
                    len++;
                    x++;
                }
                //<<len<<" "<<x<<endl;
                if(len==(int)s1[j].size())
                {
                    flag=true;
                    k=x;
                    continue;
                }
                if(a[k]!=b[k])
                {
                    cnt++;
                }
                k++;
            }
            //cout<<endl;
            if(cnt==0)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
