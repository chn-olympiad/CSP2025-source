// #include<bits/stdc++.h>
// using namespace std;
// bool cmp(int a,int b)
// {
//     //return a>b;
// }
// int main()
// {
//     freopen("club.in","r",stdin);
//     freopen("club.out","w",stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(0),cout.tie(0);
//     int T;
//     cin>>T;
//     while(T--)
//     {
//         int n;
//         cin>>n;
//         int in1[100005],in2[100005],in3[100005];
//         int use1=n/2,use2=n/2,use3=n/2;
//         int cnt1=1,cnt2=1,cnt3=1;
//         // for(int i=1;i<=n;i++)
//         // {
//         //     cout<<in1[i]<<' '<<in2[i]<<' '<<in3[i]<<'\n';
//         // }
//         for(int i=1;i<=n;i++)
//         {
//             in1[i]=in2[i]=in3[i]=0;
//         }
//         for(int i=1;i<=n;i++)
//         {
//             int x,y,z;
//             cin>>x>>y>>z;
//             if(x==max({x,y,z}))
//             {
//                 in1[cnt1]=x;
//                 ++cnt1;
//                 //cout<<"We are now in 1"<<'\n';
//                 //cout<<x<<' '<<cnt1<<'\n';
//             }
//             else if(y==max({x,y,z}))
//             {
//                 in2[cnt2]=y;
//                 ++cnt2;
//                 //cout<<"We are now in 2"<<'\n';
//                 //cout<<y<<' '<<cnt2<<'\n';
//             }
//             else if(z==max({x,y,z}))
//             {
//                 in3[cnt3]=z;
//                 ++cnt3;
//                 //cout<<"We are now in 3"<<'\n';
//                 //cout<<z<<' '<<cnt3<<'\n';
//             }
//             // in1[cnt1]=x,in2[cnt2]=x,in3[cnt3]=x;
//             // cnt1++,cnt2++,cnt3++;
//         }
//         // for(int i=1;i<=n;i++)
//         // {
//         //     cout<<in1[i]<<' '<<in2[i]<<' '<<in3[i]<<'\n';
//         // }
//         sort(in1+1,in1+1+cnt1,cmp);
//         sort(in2+1,in2+1+cnt2,cmp);
//         sort(in3+1,in3+1+cnt3,cmp);
//         int ans1=0,ans2=0,ans3=0;
//         // for(int i=1;i<=n/2;i++)
//         // {
//         //     ans1+=in1[i];
//         //     //cout<<in1[i]<<'\n';
//         //     ans2+=in2[i];
//         //     //cout<<in2[i]<<'\n';
//         //     ans3+=in3[i];
//         //     //cout<<in3[i]<<'\n';
//         //     //cout<<i<<' '<<ans1<<' '<<ans2<<' '<<ans3<<' '<<'\n';
//         // }

//         //cout<<ans1<<' '<<ans2<<' '<<ans3<<' '<<'\n';
//         cout<<ans1+ans2+ans3<<'\n';
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// struct val
// {
//     int a,b,c;
// }value[100005];
// bool cmp(val x,val y)
// {
//     if(x.a==y.a)
//     {
//         if(x.b==y.b)
//         {
//             // if(x.c==y.c)
//             // {
//             //     return x.c>y.c
//             // }
//             return x.c>y.c;
//         }
//         return x.b>y.b;
//     }
//     return x.a>y.a;
// }
// int main()
// {
//     freopen("club.in","r",stdin);
//     freopen("club.out","w",stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(0),cout.tie(0);
//     int T;
//     cin>>T;
//     while(T--)
//     {
//         int n;
//         cin>>n;
//         for(int i=1;i<=n;i++)
//         {
//             int x,y,z;
//             cin>>x>>y>>z;
//             value[i].a=x,value[i].b=y,value[i].c=z;
//         }
//         sort(value+1,value+1+n,cmp);
//         int nn=n/2;
//         int ans=0;
//         // for(int i=1;i<=nn;i++)
//         // {
//         //     ans+=value[i].a;
//         //     cout<<ans<<'\n';
//         // }
//         // for(int i=1;i<=nn;i++)
//         // {
//         //     ans+=value[i].b;
//         // }
//         // for(int i=1;i<=nn;i++)
//         // {
//         //     ans+=value[i].c;
//         // }
//         int cnt1=n/2;
//         int cnt2=n/2;
//         int cnt3=n/2;
//         for(int i=1;i<=n;i++)
//         {
//             if(value[i].a==max({value[i].a,value[i].b,value[i].c})&&--cnt1>=0) ans+=value[i].a;
//         }
//         for(int i=1;i<=n;i++)
//         {
//             if(value[i].b==max(value[i].b,value[i].c)&&--cnt2>=0) ans+=value[i].b;
//         }
//         for(int i=1;i<=n;i++)
//         {
//             if(--cnt3>=0) ans+=value[i].c;
//         }
//         cout<<ans<<'\n';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a>b;
}
// int subtask1(int n)
// {
//     int a[100005][5];
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= 3; j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     long long ans = 0;
//     for (int i = 1; i <= 3; i++)
//     {
//         for (int j = 1; j <= 3; j++)
//         {
//             if (i == j)
//             {
//                 continue;
//             }
//             ans = max(ans, 1LL * a[1][i] + a[2][j]);
//         }
//     }
//     return ans;
// }
int subtask3(int n)
{

}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n == 2)
        {
            int a[100005][5];
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= 3; j++)
                {
                    cin >> a[i][j];
                }
            }
            long long ans = 0;
            for (int i = 1; i <= 3; i++)
            {
                for (int j = 1; j <= 3; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    ans = max(ans, 1LL * a[1][i] + a[2][j]);
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        bool sub1=1;
        int in1[100005], in2[100005], in3[100005];
        int use1 = n / 2, use2 = n / 2, use3 = n / 2;
        int cnt1 = 1, cnt2 = 1, cnt3 = 1;
        bool sub2=1;
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<in1[i]<<' '<<in2[i]<<' '<<in3[i]<<'\n';
        // }
        int tim[100005][5];
        for (int i = 1; i <= n; i++)
        {
            in1[i] = in2[i] = in3[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            if(y&&z)
            {
                sub1=0;
            }
            if(z)
            {
                sub2=0;
            }
            if (x == max({x, y, z}))
            {
                in1[cnt1] = x;
                ++cnt1;
                //cout<<"We are now in 1"<<'\n';
                //cout<<x<<' '<<cnt1<<'\n';
            }
            else if (y == max({x, y, z}))
            {
                in2[cnt2] = y;
                ++cnt2;
                //cout<<"We are now in 2"<<'\n';
                //cout<<y<<' '<<cnt2<<'\n';
            }
            else if (z == max({x, y, z}))
            {
                in3[cnt3] = z;
                ++cnt3;
                //cout<<"We are now in 3"<<'\n';
                //cout<<z<<' '<<cnt3<<'\n';
            }
            // in1[cnt1]=x,in2[cnt2]=x,in3[cnt3]=x;
            // cnt1++,cnt2++,cnt3++;
        }
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<in1[i]<<' '<<in2[i]<<' '<<in3[i]<<'\n';
        // }
        if(sub1)
        {
            long long ans=0;
            sort(in1+1,in1+cnt1+n,cmp);
            for(int i=1;i<=use1;i++)
            {
                ans+=in1[i];
            }
            cout<<ans<<'\n';
            continue;
        }
        // if(sub2)
        // {
        //     long long ans=0;

        // }
        sort(in1 + 1, in1 + 1 + cnt1, cmp);
        sort(in2 + 1, in2 + 1 + cnt2, cmp);
        sort(in3 + 1, in3 + 1 + cnt3, cmp);
        int ans1 = 0, ans2 = 0, ans3 = 0;
        for(int i=1;i<=n/2;i++)
        {
            ans1+=in1[i];
            //cout<<in1[i]<<'\n';
            ans2+=in2[i];
            //cout<<in2[i]<<'\n';
            ans3+=in3[i];
            //cout<<in3[i]<<'\n';
            //cout<<i<<' '<<ans1<<' '<<ans2<<' '<<ans3<<' '<<'\n';
        }

        //cout<<ans1<<' '<<ans2<<' '<<ans3<<' '<<'\n';
        cout << ans1 + ans2 + ans3 << '\n';
    }
    return 0;
}

//明年注意时间分配
//:wq