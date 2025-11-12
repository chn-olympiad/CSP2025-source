#include<bits/stdc++.h>
using namespace std;
string a[200500][5],s1,s2;
int b[200500][5];
long long n,q,sum;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=2;j++)
    {
        for(int k=0;k<a[i][j].size();k++)
        if(a[i][j][k]=='b')
        {b[i][j]=k;break;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>s1>>s2;int x,y;
        for(int j=0;j<=s1.size();j++)
        {
        if(s1[j]=='b')
        {x=j;
        break;
        }
        }
        for(int j=0;j<=s2.size();j++)
        {
            if(s2[j]=='b')
            {
                y=j;break;
            }

        }
        for(int j=1;j<=n;j++)
        {
            if(x>=b[j][1]&&a[j][1].size()-b[j][1]<=s1.size()-x&&x-y==b[j][1]-b[j][2])sum++;
        }
        cout<<sum<<endl;
        sum=0;
    }

}
