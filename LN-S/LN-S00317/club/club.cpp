#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int nn=n/2;
        vector<int>v;
        long long cnt=0;
        int a[100010][10];
        int b[10];
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);

        for(int i=0;i<n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            int x=0,y=0;
            for(int j=0;j<3;j++)
            {
                if(a[i][j]>=x)
                {
                    x=a[i][j];
                    y=j;
                }
            }
            a[i][3]=x;
            a[i][4]=y;
            b[y]++;
            cnt+=x;
        }
        int k=4;

        for(int i=0;i<3;i++)
        {
            if(b[i]>nn)
            {
                k=i;
            }
        }
        if(k==4)
        {
            cout<<cnt<<endl;
        }
        else
        {
            int e=b[k]-nn;
            for(int i=0;i<n;i++)
            {
                if(a[i][4]==k)
                {
                    int c=a[i][3];
                    int d;
                    if(k==0)
                    {
                        d=c-max(a[i][1],a[i][2]);
                    }
                    else if(k==1)
                    {
                        d=c-max(a[i][0],a[i][2]);
                    }
                    else
                    {
                        d=c-max(a[i][0],a[i][1]);
                    }
                    v.push_back(d);
                }
            }
            sort(v.begin(),v.end());
            for(int i=0;i<e;i++)
            {
                cnt-=v[i];
            }
            cout<<cnt<<endl;
        }

    }
    return 0;
}
