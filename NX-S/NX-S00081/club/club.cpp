#include<bits/stdc++.h>
using namespace std;
int a[100001];
struct w{
    int id;
    int myd;
    };
bool operator<(w a,w b)
{
    if(a.myd==b.myd)
        return a.id>b.id;
    return a.myd<b.myd;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        priority_queue<w> q1;
        priority_queue<w> q2;
        priority_queue<w> q3;
        for(int j=0;j<=n-1;j++)
        {
            int q;
            cin>>q;
            q1.push({j,q});
            cin>>q;
            q2.push({j,q});
            cin>>q;
            q3.push({j,q});
        }
        int dui1=0,dui2=0,dui3=0,sum=0;
        for(int j=0;j<=n-1;j++)
        {
            if(q1.top().myd!=0)
            {
                if(dui1<n/2)
                {
                    int z=q1.top().id;
                    if(a[z]!=0)
                        q1.pop();
                    else
                    {
                        a[z]++;
                        dui1++;
                        sum=sum+q1.top().myd;
                        q1.pop();
                    }
                }
            }
            if(q2.top().myd!=0)
            {
                if(dui2<n/2)
                {
                    int x=q2.top().id;
                    if(a[x]!=0)
                        q2.pop();
                    else
                    {
                        a[x]++;
                        dui2++;
                        sum=sum+q2.top().myd;
                        q2.pop();
                    }
                }
            }
            if(q3.top().myd!=0)
            {
                if(dui3<n/2)
                {
                    int y=q3.top().id;
                    if(a[y]!=0)
                        q3.pop();
                    else
                    {
                        a[y]++;
                        dui3++;
                        sum=sum+q3.top().myd;
                        q3.pop();
                    }
                }
            }
        }
        for(int j=0;j<=n-1;j++)
            a[j]=0;
        cout<<sum<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
