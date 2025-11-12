#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
struct node
{
    int num;
    int x;
};
node a[100010][5];
int cnt[100010];
bool cmp(node x,node y)
{
    return x.x>y.x;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        /*for(int i=1;i<=n;i++)
        {
            vector<node> tmp;
            for(int j=1;j<=3;j++)
            {
                int x;
                cin>>x;
                tmp.push_back({j,x});
            }
            sort(tmp.begin(),tmp.end(),cmp);
            for(int j=0;j<3;j++)
            {
                a[i][j].num=tmp[j].num;
                a[i][j].x=tmp[j].x;
            }
        }
        /*for(int i=1;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<a[i][j].x<<" ";
            }
            cout<<endl;
        }*/
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j].x;
                a[i][j].num=i;
            }
        }
        memset(cnt,0,sizeof(cnt));
        int ans=0;
        /*for(int i=1;i<=n;i++)
        {
            int j=1;
            cnt[a[i][j].num]++;
            while(cnt[a[i][j].num]>n/2)
            {
                int maxn=0;
                for(int k=1;k<=n;k++)
                {
                    maxn=max(maxn,a[k][j+1]);
                }
            }
        }*/
        vector<int> v[100010];


        vector<node> v1;
        for(int i=1;i<=n;i++)
        {
            v1.push_back(a[i][1]);
        }
        sort(v1.begin(),v1.end(),cmp);
        for(int i=0;i<n/2;i++)
        {
            cnt[v1[i].num]++;
            v[v1[i].num].push_back(v1[i].x);
            ans+=v1[i].x;
        }
        vector<node> v2;
        for(int i=1;i<=n;i++)
        {
            v2.push_back(a[i][2]);
        }
        sort(v2.begin(),v2.end(),cmp);
        for(int i=0;i<n/2;i++)
        {
            cnt[v2[i].num]++;
            v[v2[i].num].push_back(v2[i].x);
            ans+=v2[i].x;
        }
        vector<node> em1,em2;
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]==0)
            {
                em1.push_back(a[i][1]);
                em2.push_back(a[i][2]);
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<ans<<endl;
        //int index=-1;
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]>1)
            {
                int minn1=0x7F7F7F7F,minn2=0x7F7F7F7F;
                int p1=0,p2=0;
                bool flag=false;
                for(int k=0;k<em1.size();k++)
                {
                    if(cnt[em1[k].num]==1)
                    {
                        continue;
                    }
                    //minn1=min(minn1,a[i][1].x-em1[k]);
                    if(a[i][1].x-em1[k].x<minn1)
                    {
                        minn1=a[i][1].x-em1[k].x;
                        p1=em1[k].num;
                    }
                    if(a[i][2].x-em2[k].x<minn2)
                    {
                        minn2=a[i][2].x-em2[k].x;
                        p2=em2[k].num;
                    }
                    //minn2=min(minn2,a[i][2].x-em2[k]);
                    //cout<<"jjjj"<<a[em1[k].num][3].x<<endl;
                    if(a[em1[k].num][3].x>em1[k].x&&a[em1[k].num][3].x>em2[k].x)
                    {
                        //cout<<"223"<<endl;
                        minn1=a[i][1].x-em1[k].x;
                        p1=em1[k].num;
                        minn2=a[i][2].x-em2[k].x;
                        p2=em2[k].num;
                        flag=true;
                        if(v[i][0]<v[i][1])
                        {
                            ans-=minn1;
                            cnt[i]--;
                            v[i][0]=v[i][1];
                            v[i].pop_back();
                            v[p1].push_back(a[i][1].x-minn1);
                            cnt[p1]++;
                        }
                        else
                        {
                            ans-=minn2;
                            cnt[i]--;
                            v[i].pop_back();
                            v[p2].push_back(a[i][2].x-minn2);
                            cnt[p2]++;
                        }
                        break;
                    }
                }
                if(flag==true)
                {
                    continue;
                }
                if(minn1<minn2)
                {
                    ans-=minn1;
                    cnt[i]--;
                    v[i][0]=v[i][1];
                    v[i].pop_back();
                    v[p1].push_back(a[i][1].x-minn1);
                    cnt[p1]++;
                }
                else if(minn1>minn2)
                {
                    ans-=minn2;
                    cnt[i]--;
                    v[i].pop_back();
                    v[p2].push_back(a[i][2].x-minn2);
                    cnt[p2]++;
                }
                else
                {
                    if(v[i][0]<v[i][1])
                    {
                        ans-=minn1;
                        cnt[i]--;
                        v[i][0]=v[i][1];
                        v[i].pop_back();
                        v[p1].push_back(a[i][1].x-minn1);
                        cnt[p1]++;
                    }
                    else
                    {
                        ans-=minn2;
                        cnt[i]--;
                        v[i].pop_back();
                        v[p2].push_back(a[i][2].x-minn2);
                        cnt[p2]++;
                    }
                }
            }
            //cout<<ans<<endl;
        }
        /*for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }*/


        cout<<ans<<endl;


        /*for(int j=1;j<=3;j++)
        {
            vector<node> v;
            for(int i=1;i<=n;i++)
            {
                v.push_back(a[i][j]);
            }
            sort(v.begin(),v.end(),cmp);
            for(int i=0;i<n/2;i++)
            {
                cnt[v[i].num]++;
            }
        }
        vector<node> v3;
        for(int i=1;i<=n;i++)
        {
            v3.push_back(a[i][3]);
        }
        sort(v3.begin(),v3.end(),cmp);
        for(int i=0;i<n/2;i++)
        {
            if(v3[i].x>v[v3[i].num][0])
            {
                ans+=(v3[i].x-v[v3[i].num][0]);
            }
        }
        cout<<ans<<endl;*/

        for(int i=1;i<=n;i++)
        {
            if(v[i].size()==0)
            {
                continue;
            }
            if(a[i][3].x>v[i][0])
            {
                ans+=(a[i][3].x-v[i][0]);
            }
            //cout<<v[i][0]<<" ";
        }
        cout<<ans<<endl;
    }
}
