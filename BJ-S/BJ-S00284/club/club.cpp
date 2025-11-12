#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int v[4]={0};
int stf=0,n;
int s[100005][4];
struct req
{
    int stf,pos,c;
};
bool cmp(req a,req b)
{
    return a.stf<b.stf;
}
req s2[100005];
bool u[100005];
void dfs(int st,int tp)
{
    if(st>n)
    {
        stf=max(stf,tp);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(v[i]<n/2)
        {
            v[i]++;
            dfs(st+1,tp+s[st][i]);
            v[i]--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(v,0,4);
        stf=0;
        cin>>n;
        if(n<=10)
        {
            for(int i=1;i<=n;i++)
            {
                cin>>s[i][1]>>s[i][2]>>s[i][3];
            }
            dfs(1,0);
            cout<<stf<<endl;
        }
        else
        {
            memset(u,0,sizeof(u));
            for(int i=1;i<=n;i++)
            {
                cin>>s2[3*i-2].stf>>s2[3*i-1].stf>>s2[3*i].stf;
                s2[3*i-2].c=1;
                s2[3*i-1].c=2;
                s2[3*i].c=3;
                s2[3*i-2].pos=i;
                s2[3*i-1].pos=i;
                s2[3*i].pos=i;
            }
            sort(s2,s2+3*n+1,cmp);
            for(int i=3*n;i>=1;i--)
            {
                if(u[s2[i].pos]==false&&v[s2[i].c]<n/2)
                {
                    v[s2[i].c]++;
                    u[s2[i].pos]=true;
                    stf+=s2[i].stf;
                }
            }
            cout<<stf<<endl;
        }
    }
    return 0;
}