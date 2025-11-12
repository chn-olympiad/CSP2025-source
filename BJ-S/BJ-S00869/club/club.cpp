#include<bits/stdc++.h>
using namespace std;
vector<int> anss;
vector<vector<int>> a;
int t,n,ans,st1,st2,st3;
int ft1(vector<int> t,vector<int> r)
{
    return t[0]>r[0]?true:false;
}
int ft2(vector<int> t,vector<int> r)
{
    return t[1]>r[1]?true:false;
}
int ft3(vector<int> t,vector<int> r)
{
    return t[2]>r[2]?true:false;
}
void ppp()
{
    for(int i=0;i<a.size();i++)
    {
        cout << a[i][0] << a[i][1] << a[i][2] << endl;
    }
}
int main()
{

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int l=0;l<t;l++)
    {
        a.clear();
        ans=0;st1=0;st2=0;st3=0;
        cin >> n;
        for(int j=0;j<n;j++)
        {
            int tmp1,tmp2,tmp3;
            vector<int> tmp;
            cin >> tmp1 >> tmp2 >> tmp3;
            tmp.push_back(tmp1);
            tmp.push_back(tmp2);
            tmp.push_back(tmp3);
            tmp.push_back(0);
            a.push_back(tmp);
        }
        srt:
        sort(a.begin(),a.end(),ft1);
        for(int i=0;i<a.size();i++)
        {
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]&&a[i][3]==0)
            {
                if(st1<n/2){
                ans += a[i][0];
                a[i][3] = 1;
                st1++;
                }
                else{
                    for(int j=0;j<a.size();j++)
                    {
                        if(a[j][3]==1&&(max(a[j][1],a[j][2])>a[j][0]-a[i][0]))
                        {
                            a[i][3]=1;
                            a[j][3]=0;
                            ans -= a[j][0];
                            ans += a[i][0];
                            continue;
                        }
                    }
                    a[i][0]=-1;
                    continue;
                }
            }

        }
        sort(a.begin(),a.end(),ft2);
        for(int i=0;i<a.size();i++)
        {
            if(a[i][1]>=a[i][2]&&a[i][3]==0)
            {
                if(st2<n/2){
                ans += a[i][1];
                a[i][3] = 2;
                st2++;
                }
                else{
                        for(int j=0;j<a.size();j++)
                    {
                        if(a[j][3]==2&&(max(a[j][0],a[j][2])>a[j][1]-a[i][1]))
                        {
                            a[i][3]=2;
                            a[j][3]=0;
                            ans -= a[j][1];
                            ans += a[i][1];
                            continue;
                        }
                    }
                    a[i][1]=-1;
                    continue;
                }
            }

        }
        sort(a.begin(),a.end(),ft3);
        for(int i=0;i<a.size();i++)
        {
            if(a[i][3]==0)
            {
                if(st3<n/2){
                ans += a[i][2];
                a[i][3] = 3;
                st3++;
                }
                else{
                         for(int j=0;j<a.size();j++)
                    {
                        if(a[j][3]==3&&(max(a[j][0],a[j][1])>a[j][2]-a[i][2]))
                        {
                            a[i][3]=3;
                            a[j][3]=0;
                            ans -= a[j][2];
                            ans += a[i][2];
                            continue;
                        }
                    }
                    a[i][2]=-1;
                    continue;
                }
            }

        }
        if(st1+st2+st3<n)
        {
            goto srt;
        }
        end:
        anss.push_back(ans);
    }
    for(int i=0;i<anss.size();i++)
    {
        cout << anss[i] << endl;
    }
    return 0;
}
