#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
string as[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    string li;
    for(int i=1;i<=n;i++)
    {
        int t=a[i];
        int s=0;
        while(t!=0)
        {
            li[s]=t%2;
            t/=2;
            s++;
        }
        for(int j=s;j>=0;j++)
        {
            as[i][j]=li[s-j];
        }
    }
    for(int l=0;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            for(int i=l;i<=r;i++)
            {
                for(int j=0;j<=as[i].size()-1;j++)
                {
                    if(a[i]==)
                }
            }
        }
    }
    return 0;
}
