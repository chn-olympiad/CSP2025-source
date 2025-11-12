#include<bits/stdc++.h>
using namespace std;
int n,m;
string ans[200000][2];
string que[200000][2];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>ans[i][0]>>ans[i][1];
    for(int i=0;i<m;i++)
    {
        int sum=0;
        cin>>que[i][0]>>que[i][1];
        for(int j=0;j<que[i][0].size();j++)
        {
            for(int k=0;k+j<que[i][0].size();k++)
            {
                string q1=que[i][0].substr(k,j+1);
                string q2=que[i][1].substr(k,j+1);
                string x1=que[i][0].substr(0,k);
                string y1=que[i][0].substr(k+j+1,que[i][0].size()-1-k-j-1);
                string x2=que[i][1].substr(0,k);
                string y2=que[i][1].substr(k+j+1,que[i][1].size()-1-k-j-1);
                if(x1!=x2 || y1!=y2)
                    continue;
                for(int t=0;t<n;t++)
                {
                    if(ans[t][0]==q1 && ans[t][1]==q2)
                        sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
