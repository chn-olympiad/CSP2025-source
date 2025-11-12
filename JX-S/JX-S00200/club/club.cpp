#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
    int t;
    long long n;
    pair<long long,int> maxn1[n];
    long long cha[n];
    pair<long long,int> maxn2[n];
    long long sum=0;
    long long count[3]={0};
    long long xiabiao[3][n];
    memset(maxn1,0,sizeof(maxn1));
    memset(maxn2,0,sizeof(maxn2));
    memset(cha,0,sizeof(cha));
    memset(xiabiao,0,sizeof(xiabiao));
    sum=0;
    memset(count,0,sizeof(count));
    cin>>t;
    while(t--)
    {

        cin>>n;


        for(long long i=0;i<n;i++)
        {
            long long a[i][3];
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2])
            {
                maxn1[i].first=a[i][0];
                maxn1[i].second=0;
                if(a[i][1]>=a[i][2])
                {
                    maxn2[i].first=a[i][1];
                    maxn2[i].second=1;

                }
                else{
                    maxn2[i].first=a[i][2];
                    maxn2[i].second=2;

                }
                cha[i]=maxn1[i].first-maxn2[i].first;
            }
            else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2])
            {
                maxn1[i].first=a[i][1];
                maxn1[i].second=1;
                if(a[i][0]>=a[i][2])
                {
                    maxn2[i].first=a[i][0];
                    maxn2[i].second=0;

                }
                else{
                    maxn2[i].first=a[i][2];
                    maxn2[i].second=2;

                }
                cha[i]=maxn1[i].first-maxn2[i].first;
            }
            else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][0])
            {
                maxn1[i].first=a[i][2];
                maxn1[i].second=2;
                if(a[i][1]>=a[i][0])
                {
                    maxn2[i].first=a[i][1];
                    maxn2[i].second=1;

                }
                else{
                    maxn2[i].first=a[i][0];
                    maxn2[i].second=0;

                }

            }
        }

        for(long long i=0;i<n;i++)
        {
            sum=sum+maxn1[i].first;


            xiabiao[maxn1[i].second][count[maxn1[i].second]]=maxn1[i].second;
            count[maxn1[i].second]++;
        }
        if(count[0]>(n/2))
        {
            long long t=count[0]-(n/2);
            long long mincha=INT_MAX;
            long long minchaxiabiao=INT_MAX;
            for(long long i=0;i<t;i++)
            {
                for(long long j=0;j<=count[0];j++)
                {
                    if(cha[xiabiao[0][j]]<mincha)
                    {
                        mincha=cha[xiabiao[0][j]];
                        minchaxiabiao=xiabiao[0][j];
                    }
                }
                cha[minchaxiabiao]=INT_MAX;
                sum=sum-maxn1[minchaxiabiao].first+maxn2[minchaxiabiao].first;
            }
        }
        else if(count[1]>(n/2))
        {
            long long t=count[1]-(n/2);
            long long mincha=INT_MAX;
            long long minchaxiabiao=INT_MAX;
            for(long long  i=0;i<t;i++)
            {
                for(long long j=0;j<=count[1];j++)
                {
                    if(cha[xiabiao[1][j]]<mincha)
                    {
                        mincha=cha[xiabiao[1][j]];
                        minchaxiabiao=xiabiao[1][j];
                    }
                }
                cha[minchaxiabiao]=INT_MAX;
                sum=sum-maxn1[minchaxiabiao].first+maxn2[minchaxiabiao].first;
            }
        }
        else if(count[2]>(n/2))
        {
            long long t=count[2]-(n/2);
            long long mincha=INT_MAX;
            long long minchaxiabiao=INT_MAX;
            for(long long i=0;i<t;i++)
            {
                for(long long j=0;j<=count[2];j++)
                {
                    if(cha[xiabiao[2][j]]<mincha)
                    {
                        mincha=cha[xiabiao[2][j]];
                        minchaxiabiao=xiabiao[2][j];
                    }
                }
                cha[minchaxiabiao]=INT_MAX;
                sum=sum-maxn1[minchaxiabiao].first+maxn2[minchaxiabiao].first;
            }
        }
        cout<<sum<<endl;
        memset(maxn1,0,sizeof(maxn1));
        memset(maxn2,0,sizeof(maxn2));
        memset(cha,0,sizeof(cha));
        memset(xiabiao,0,sizeof(xiabiao));
        sum=0;
        memset(count,0,sizeof(count));
    }
    return 0;
}
