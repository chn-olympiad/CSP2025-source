#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int t,n;
vector<int> nee1;
vector<int> nee2;
vector<int> nee3;
pair<int,pair<int,int>> cmop[100001];
bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
{
    return a.first>b.first;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int kpi=1;kpi<=t;kpi++)
    {
        priority_queue<int,vector<int>,greater<int>> af[4];
        int dist[100001];
        cin>>n;
        nee1.resize(100001);
        nee2.resize(100001);
        nee3.resize(100001);
        for(int i=1;i<=n;i++)
        {
            cin>>nee1[i]>>nee2[i]>>nee3[i];
            int able=0;
            int lovmax=max(max(nee1[i],nee2[i]),nee3[i]);
            if(lovmax==nee1[i])
            {
                if(able==0)
                {
                    able=1;
                    dist[i]=lovmax-max(nee2[i],nee3[i]);
                }
                else
                {
                    able=-1;
                }
            }
            if(lovmax==nee2[i])
            {
                if(able==0)
                {
                    able=2;
                    dist[i]=lovmax-max(nee1[i],nee3[i]);
                }
                else
                {
                    able=-1;
                }
            }
            if(lovmax==nee3[i])
            {
                if(able==0)
                {
                    able=3;
                    dist[i]=lovmax-max(nee2[i],nee1[i]);
                }
                else
                {
                    able=-1;
                }
            }
            cmop[i]=make_pair(lovmax,make_pair(i,able));
        }
        sort(cmop+1,cmop+n+1,cmp);
        int am[4];
        am[1]=am[2]=am[3]=0;
        long long mxsum=0;
        for(int i=1;i<=n;i++)
        {
            bool ok=false;
            int dok=0;
            if(cmop[i].second.second!=-1)
            {
                am[cmop[i].second.second]+=1;
                if(am[cmop[i].second.second]==n/2)
                {
                    ok=true;
                    dok=cmop[i].second.second;
                }
                af[cmop[i].second.second].push(dist[cmop[i].second.first]);
            }
            mxsum+=cmop[i].first;
            if(ok==true)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(dok==cmop[j].second.second)
                    {
                        int man=cmop[j].second.first;
                        if(dok==1)
                        {

                            if(dist[man]>af[1].top())
                            {
                                mxsum-=af[1].top();
                                af[1].pop();
                                af[1].push(dist[man]);
                            }
                            else{cmop[j].first=max(nee2[man],nee3[man]);}
                            cmop[j].second.second=-1;
                            mxsum+=cmop[j].first;
                        }
                        if(dok==2)
                        {
                            if(dist[man]>af[2].top())
                            {
                                mxsum-=af[2].top();
                                af[2].pop();
                                af[2].push(dist[man]);
                            }
                            else{cmop[j].first=max(nee1[man],nee3[man]);}
                            cmop[j].second.second=-1;
                            mxsum+=cmop[j].first;
                        }
                        if(dok==3)
                        {
                            if(dist[man]>af[3].top())
                            {
                                mxsum-=af[3].top();
                                af[3].pop();
                                af[3].push(dist[man]);
                            }
                            else{cmop[j].first=max(nee2[man],nee1[man]);}
                            cmop[j].second.second=-1;
                            mxsum+=cmop[j].first;
                        }
                    }
                    else
                    {
                        mxsum+=cmop[j].first;
                    }
                }
                break;
            }
        }
        cout<<mxsum<<endl;
    }
    return 0;
}
