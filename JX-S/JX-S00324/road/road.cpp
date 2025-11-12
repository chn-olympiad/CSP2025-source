#include<bits/stdc++.h>
using namespace std;
int ans=0;
string a[200010];
string b[200010];
int main()
{
    freopen("replaced.in","r",stdin);
    freopen("replaced.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    
    while(q--)
    {
        string s,s1;
        cin>>s>>s1;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-a[i].size()+1;j++)
            {
                string k="";string k1=s;
                for(int ii=j;ii<=j+a[i].size()-1;ii++)
                {
                    k+=s[ii];
                }
                if(k==a[i])
                {     int mm=1;
                     for(int jj=j;jj<=j+a[i].size()-1;jj++)
                     {
                         k1[jj]=b[i][mm]; mm++;
                     }
                     if(k1==s1) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}