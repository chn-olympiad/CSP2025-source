/*
lg 592080 关注谢谢喵！

freopen((FILE_NAME+".in").c_str(),"w",stdin);
freopen((FILE_NAME+".out").c_str(),"r",stdout);

14:35 开始写题
15:10 250行初稿完成
15:25 350行过不了，发现问题，重写
15:41 过大样例
*/
#include<bits/stdc++.h>
#define MORE_TEST
using namespace std;
const string FILE_NAME="club";
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    #ifndef LOCAL
        freopen((FILE_NAME+".in").c_str(),"r",stdin);
        freopen((FILE_NAME+".out").c_str(),"w",stdout);
    #endif

    int T=1;
    #ifdef MORE_TEST
        cin>>T;
    #endif

    while (T--)
    {
        int n;
        cin>>n;

        vector<vector<int>> a(n+1,vector<int>(3));
        int pre_ans=0;
        priority_queue<int> q1,q2,q3;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            int ma=max({a[i][0],a[i][1],a[i][2]});
            pre_ans+=ma;
            a[i][0]-=ma;
            a[i][1]-=ma;
            a[i][2]-=ma;
            if (!a[i][0])
                q1.push(max(a[i][1]-a[i][0],a[i][2]-a[i][0]));
            else if (!a[i][1])
                q2.push(max(a[i][0]-a[i][1],a[i][2]-a[i][1]));
            else
                q3.push(max(a[i][0]-a[i][2],a[i][1]-a[i][2]));
        }

        int sum=0;
        while ((int)q1.size()>n/2)
        {
            sum+=q1.top();
            q1.pop();
        }
        while ((int)q2.size()>n/2)
        {
            sum+=q2.top();
            q2.pop();
        }
        while ((int)q3.size()>n/2)
        {
            sum+=q3.top();
            q3.pop();
        }

        cout<<pre_ans+sum<<'\n';
    }

    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0

1
4
0 1 0
0 1 0
0 2 0
0 2 0

1
2
10 9 8
4 0 0
*/

//下为依托，慎入
/*
#include<bits/stdc++.h>
#define MORE_TEST
using namespace std;
const string FILE_NAME="club";
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    #ifndef LOCAL
        freopen((FILE_NAME+".in").c_str(),"r",stdin);
        freopen((FILE_NAME+".out").c_str(),"w",stdout);
    #endif

    int T=1;
    #ifdef MORE_TEST
        cin>>T;
    #endif

    while (T--)
    {
        int n;
        cin>>n;

        vector<vector<int>> a(n+1,vector<int>(3));
        int pre_ans=0;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            int ma=max({a[i][0],a[i][1],a[i][2]});
            pre_ans+=ma;
            a[i][0]-=ma;
            a[i][1]-=ma;
            a[i][2]-=ma;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1,q2,q3;
        for (int i=1;i<=n;i++)
        {
            if (a[i][0]==max({a[i][0],a[i][1],a[i][2]}))
            {
                if ((int)q1.size()<n/2)
                    q1.emplace(a[i][0],i);
                else
                {
                    auto x=q1.top().first,y=q1.top().second;
                    if (x<a[i][0])
                    {
                        q1.pop();
                        q1.emplace(a[i][0],i);
                        if (a[y][1]==max(a[y][1],a[y][2]))
                        {
                            if ((int)q2.size()<n/2)
                                q2.emplace(a[y][1],y);
                            else
                            {
                                if (q2.top().first<a[y][1])
                                {
                                    q3.emplace(a[q2.top().second][2],q2.top().second);
                                    q2.pop();
                                    q2.emplace(a[y][1],y);
                                }
                                else
                                    q3.emplace(a[y][2],y);
                            }
                        }
                        else
                        {
                            if ((int)q3.size()<n/2)
                                q3.emplace(a[y][2],y);
                            else
                            {
                                if (q3.top().first<a[y][2])
                                {
                                    q2.emplace(a[q3.top().second][1],q3.top().second);
                                    q3.pop();
                                    q3.emplace(a[y][2],y);
                                }
                                else
                                    q3.emplace(a[y][2],y);
                            }
                        }
                    }
                    else
                    {
                        if (a[i][1]==max({a[i][1],a[i][2]}))
                        {
                            if ((int)q2.size()<n/2)
                                q2.emplace(a[i][1],i);
                            else
                            {
                                if (q2.top().first<a[i][1])
                                {
                                    q3.emplace(a[q2.top().second][2],q2.top().second);
                                    q2.pop();
                                    q2.emplace(a[i][1],i);
                                }
                                else
                                    q3.emplace(a[i][2],i);
                            }
                        }
                        else
                        {
                            if ((int)q3.size()<n/2)
                                q3.emplace(a[i][2],i);
                            else
                            {
                                if (q3.top().first<a[i][2])
                                {
                                    q2.emplace(a[q3.top().second][1],q3.top().second);
                                    q3.pop();
                                    q3.emplace(a[i][2],i);
                                }
                                else
                                    q2.emplace(a[i][1],i);
                            }
                        }
                    }
                }
            }
            else if (a[i][1]==max({a[i][0],a[i][1],a[i][2]}))
            {
                if ((int)q2.size()<n/2)
                    q2.emplace(a[i][1],i);
                else
                {
                    auto x=q2.top().first,y=q2.top().second;
                    if (x<a[i][1])
                    {
                        q2.pop();
                        q2.emplace(a[i][1],i);
                        if (a[y][0]==max(a[y][0],a[y][2]))
                        {
                            if ((int)q1.size()<n/2)
                                q1.emplace(a[y][0],y);
                            else
                            {
                                if (q1.top().first<a[y][0])
                                {
                                    q3.emplace(a[q1.top().second][2],q1.top().second);
                                    q1.pop();
                                    q1.emplace(a[y][0],y);
                                }
                                else
                                    q3.emplace(a[y][2],y);
                            }
                        }
                        else
                        {
                            if ((int)q3.size()<n/2)
                                q3.emplace(a[y][2],y);
                            else
                            {
                                if (q3.top().first<a[y][2])
                                {
                                    q1.emplace(a[q3.top().second][0],q3.top().second);
                                    q3.pop();
                                    q3.emplace(a[y][2],y);
                                }
                                else
                                    q1.emplace(a[y][0],y);
                            }
                        }
                    }
                    else
                    {
                        if (a[i][0]==max({a[i][0],a[i][2]}))
                        {
                            if ((int)q1.size()<n/2)
                                q1.emplace(a[i][0],i);
                            else
                            {
                                if (q1.top().first<a[i][0])
                                {
                                    q3.emplace(a[q1.top().second][2],q1.top().second);
                                    q1.pop();
                                    q1.emplace(a[i][0],i);
                                }
                                else
                                    q3.emplace(a[i][2],i);
                            }
                        }
                        else
                        {
                            if ((int)q3.size()<n/2)
                                q3.emplace(a[i][2],i);
                            else
                            {
                                if (q3.top().first<a[i][2])
                                {
                                    q1.emplace(a[q3.top().second][0],q3.top().second);
                                    q3.pop();
                                    q3.emplace(a[i][2],i);
                                }
                                else
                                    q1.emplace(a[i][0],i);
                            }
                        }
                    }
                }
            }
            else
            {
                if ((int)q3.size()<n/2)
                    q3.emplace(a[i][2],i);
                else
                {
                    auto x=q3.top().first,y=q3.top().second;
                    if (x<a[i][2])
                    {
                        q3.pop();
                        q3.emplace(a[i][2],i);
                        if (a[y][1]==max(a[y][1],a[y][0]))
                        {
                            if ((int)q2.size()<n/2)
                                q2.emplace(a[y][1],y);
                            else
                            {
                                if (q2.top().first<a[y][1])
                                {
                                    q1.emplace(a[q2.top().second][0],q2.top().second);
                                    q2.pop();
                                    q2.emplace(a[y][1],y);
                                }
                                else
                                    q1.emplace(a[y][0],y);
                            }
                        }
                        else
                        {
                            if ((int)q1.size()<n/2)
                                q1.emplace(a[y][0],y);
                            else
                            {
                                if (q1.top().first<a[y][0])
                                {
                                    q2.emplace(a[q1.top().second][1],q1.top().second);
                                    q1.pop();
                                    q1.emplace(a[y][0],y);
                                }
                                else
                                    q2.emplace(a[y][1],y);
                            }
                        }
                    }
                    else
                    {
                        if (a[i][1]==max({a[i][1],a[i][0]}))
                        {
                            if ((int)q2.size()<n/2)
                                q2.emplace(a[i][1],i);
                            else
                            {
                                if (q2.top().first<a[i][1])
                                {
                                    q1.emplace(a[q2.top().second][0],q2.top().second);
                                    q2.pop();
                                    q2.emplace(a[i][1],i);
                                }
                                else
                                    q1.emplace(a[i][0],i);
                            }
                        }
                        else
                        {
                            if ((int)q1.size()<n/2)
                                q1.emplace(a[i][0],i);
                            else
                            {
                                if (q1.top().first<a[i][0])
                                {
                                    q2.emplace(a[q1.top().second][1],q1.top().second);
                                    q1.pop();
                                    q1.emplace(a[i][0],i);
                                }
                                else
                                    q2.emplace(a[i][1],i);
                            }
                        }
                    }
                }
            }
            
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> eq1(q1),eq2(q2),eq3(q3);
            int sum=0;
            while (!q1.empty())
            {
                cerr<<q1.top().first<<' '<<q1.top().second<<'\n';
                sum+=q1.top().first,q1.pop();
            }
            cerr<<'\n';
            while (!q2.empty())
            {
                cerr<<q2.top().first<<' '<<q2.top().second<<'\n';
                sum+=q2.top().first,q2.pop();
            }
            cerr<<'\n';
            while (!q3.empty())
            {
                cerr<<q3.top().first<<' '<<q3.top().second<<'\n';
                sum+=q3.top().first,q3.pop();
            }
            swap(q1,eq1);
            swap(q2,eq2);
            swap(q3,eq3);
            cerr<<i<<'\n';
        }

        int sum=0;
        while (!q1.empty())
        {
            cerr<<q1.top().first<<' '<<q1.top().second<<'\n';
            sum+=q1.top().first,q1.pop();
        }
        cerr<<'\n';
        while (!q2.empty())
        {
            cerr<<q2.top().first<<' '<<q2.top().second<<'\n';
            sum+=q2.top().first,q2.pop();
        }
        cerr<<'\n';
        while (!q3.empty())
        {
            cerr<<q3.top().first<<' '<<q3.top().second<<'\n';
            sum+=q3.top().first,q3.pop();
        }
        cerr<<'\n';

        cout<<pre_ans+sum<<'\n';
    }

    return 0;
}
*/