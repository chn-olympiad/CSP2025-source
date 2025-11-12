#include<bits/stdc++.h>
using namespace std;
int m,n;
string qq,ww;
string a[200001][2];
string cut(string q,int ll,int rr)
{
    if(ll>rr)
    {
        return "";
    }
    string w="";
    for(int i=ll;i<=rr;i++)
    {
        w+=q[i];
    }
    return w;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>qq>>ww;
        a[i][0]=qq;
        a[i][1]=ww;
    }
    for(int i=1;i<=m;i++)
    {
        int ans=0;
        cin>>qq>>ww;
        string u[100001];
        for(int j=0;j<qq.size()-1;j++)
        {
            if(cut(qq,0,j-1)==cut(ww,0,j-1))
            {
                for(int k=j;k<qq.size();k++)
                {
                    if(cut(qq,k+1,qq.size()-1)==cut(ww,k+1,qq.size()-1))
                    {
                        for(int l=1;l<=n;l++)
                        {
                            if(a[l][0]==cut(qq,j,k)&&a[l][1]==cut(ww,j,k))
                            {
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}