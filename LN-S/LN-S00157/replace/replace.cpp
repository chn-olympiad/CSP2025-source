#include<bits/stdc++.h>
using namespace std;
string a[2005],b[2005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    while(m--)
    {
        string A,B;
        cin>>A>>B;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(A.size()-a[i].size()+b[i].size()!=B.size())continue;
            for(int j=0;j<=A.size()-a[i].size();j++)
            {
                if(j!=0&&A[j-1]!=B[j-1])break;
                bool flag=0;
                for(int k=0;k<a[i].size();k++)
                    if(A[j+k]!=a[i][k])
                    {
                        flag=1;
                        break;
                    }
                if(flag)continue;
                for(int k=0;k<b[i].size();k++)
                    if(B[j+k]!=b[i][k])
                    {
                        flag=1;
                        break;
                    }
                if(flag)continue;
                for(int k=0;k<A.size()-j-a[i].size();k++)
                    if(A[j+a[i].size()+k]!=B[j+b[i].size()+k])
                    {
                        flag=1;
                        break;
                    }
                if(flag)continue;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
