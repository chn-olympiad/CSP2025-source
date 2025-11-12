#include<bits/stdc++.h>
using namespace std;
int m[10086][10086];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t1;
    cin>>t1;

    for(int tt=0;tt<t1;tt++)
    {
        int n;
        int maxx=0,maxn=0;
        int maxi=0,maxni=0;
        int t[10]={0},ti[10]={0};
        //m[10086][10086]={0};
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>m[i][j];
            }
        }
        for(int i=0,ii=n-1;i<n,ii>=0;i++,ii--)
        {
            for(int j=0;j<3;j++)
            {
                if(t[j]==n/2) m[i][j]=0;
                if(ti[j]==n/2) m[ii][j]=0;
                maxx=max(maxx,m[i][j]);
                maxi=max(maxi,m[ii][j]);
            }
            for(int j=0;j<3;j++)
            {
                if(m[i][j]==maxx && t[j]<n/2)
                {
                    maxn+=maxx;
                    t[j]++;
                }
                if(m[ii][j]==maxi && ti[j]<n/2)
                {
                    maxni+=maxi;
                    ti[j]++;
                }
            }
        }


        //for(int i=0;i<n;i++)
        //{
        //    cout<<m[i].a<<" "<<m[i].b<<" "<<m[i].c<<endl;
        //}
        cout<<max(maxni,maxn)<<endl;
    }
    return 0;
}
