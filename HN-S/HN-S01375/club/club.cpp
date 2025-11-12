#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fz(i,x) for(int i=0;i<x;i++)
#define pii pair<int,int>
//bool cmp(vector<int> &a,vector<int>&b,vector<int>)
int main()
{
    freopen("club1.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        //cout<<t<<"------\n";
        vector<vector<int>> ms(n+1,vector<int>(3));
        vector<vector<int>> last_push(n+1,vector<int>(3,-1));
        for(int i=1; i<=n; i++)
        {
            cin>>ms[i][0]>>ms[i][1]>>ms[i][2];
        }

        int maxnum=n/2;

        int sum=0;
        ll dp[n+1][3]= {0};
        ll lastcnt[n+1][3]= {0};
        queue<int> a[n+1][3];
        //1->n member
        for(int i=1; i<=n; i++)
        {

            for(int j=0; j<3; j++)
            {
                int pushed=-1;
                int pushednum=-1;
                dp[i][j]=0;
                lastcnt[i][j]=lastcnt[i-1][j];
                front[i][j]=front[i-1][j];
                //cout<<"f("<<i<<" "<<j<<")"<<'\t';
                dp[i][j]=dp[i-1][j];
                //lastcnt[i][j]=lastcnt[i-1][j];
                for(int k=0; k<3; k++)
                {
                    a[i][k]=a[i-1][k];
                    int target=0;
                    if(!a[i][k].empty()){
                        target=a[i][k].front();
                    }
                    //if(dp[i-1][k]>=dp[i][j])dp[i][j]=dp[i-1][k];
                    if(pushednum<ms[i][j]&&a[i][k].size()+1<=maxnum&&dp[i][j]<dp[i-1][k]+ms[i][j])
                    {
                        pushed=k;
                        pushednum=ms[i][j];
                        dp[i][j]=dp[i-1][k]+ms[i][j];
                        //cout<<dp[i-1][k]<<"+"<<ms[i][j]<<"\t";

                    }else if(ms[i][j]>pushednum&&dp[i][j]<dp[i][j]+ms[i][j]-target){
                        pushed=k;
                        target=ms[i][j];
                        pushednum=ms[i][j];
                        //cout<<"pop"<<dp[i-1][k]+ms[i][j]-target<<'\n';
                        dp[i][j]=dp[i-1][k]+ms[i][j]-a[i][k].front();
                    }
                    //cout<<"";
                }
                //cout<<"\n";

                if(pushed!=-1)
                {

                    if(a[i][pushed].size()==maxnum){

                        //cout<<"pop"<<a[i][pushed].front()<<'\n';
                        a[i][pushed].pop();
                    }
                    a[i][pushed].push(ms[i][pushed]);
                    //cout<<"push"<<ms[i][pushed]<<"\n";
                };

                //cout<<'\n';
            }
            //cout<<"\n";
            //cout<<ms[i].val[ms[i].mxidx]<<'\n';
        }
        cout<<dp[n][0]<<"  "<<dp[n][1]<<" "<<dp[n][2]<<'\n';

    }
    //cout<<"iokt"<<'\n';

    return 0;
}
