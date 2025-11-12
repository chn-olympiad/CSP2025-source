#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n,ans;
struct Node{int a,b,c,id;}p[maxn];
vector<int>cnt[4];
bool cmp1(int x,int y){return p[x].a-max(p[x].b,p[x].c)>p[y].a-max(p[y].b,p[y].c);}
bool cmp2(int x,int y){return p[x].b-max(p[x].a,p[x].c)>p[y].b-max(p[y].a,p[y].c);}
bool cmp3(int x,int y){return p[x].c-max(p[x].a,p[x].b)>p[y].c-max(p[y].a,p[y].b);}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n,ans=0;
        cnt[1].clear();
        cnt[2].clear();
        cnt[3].clear();
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].a>>p[i].b>>p[i].c,p[i].id=i;
            int bst=max({p[i].a,p[i].b,p[i].c});
            if(bst==p[i].a) cnt[1].push_back(i);
            else if(bst==p[i].b) cnt[2].push_back(i);
            else cnt[3].push_back(i);
        }
        if(cnt[1].size()<=n/2&&cnt[2].size()<=n/2&&cnt[3].size()<=n/2)
        {
            for(int i=0;i<cnt[1].size();i++) ans+=p[cnt[1][i]].a;
            for(int i=0;i<cnt[2].size();i++) ans+=p[cnt[2][i]].b;
            for(int i=0;i<cnt[3].size();i++) ans+=p[cnt[3][i]].c;
        }
        else if(cnt[1].size()>n/2)
        {
            sort(cnt[1].begin(),cnt[1].end(),cmp1);
            for(int i=0;i<=n/2-1;i++) ans+=p[cnt[1][i]].a;
            for(int i=n/2;i<cnt[1].size();i++)
            {
                p[i].a=0;
                if(p[i].b>=p[i].c) cnt[2].push_back(p[i].id);
                else cnt[3].push_back(p[i].id);
            }
            if(cnt[2].size()<=n/2&&cnt[3].size()<=n/2)
            {
                for(int i=0;i<cnt[2].size();i++) ans+=p[cnt[2][i]].b;
                for(int i=0;i<cnt[3].size();i++) ans+=p[cnt[3][i]].c;
            }
            else if(cnt[2].size()>n/2)
            {
                sort(cnt[2].begin(),cnt[2].end(),cmp2);
                for(int i=0;i<=n/2-1;i++) ans+=p[cnt[2][i]].b;
                for(int i=n/2;i<cnt[2].size();i++) ans+=p[cnt[2][i]].c;
                for(int i=0;i<cnt[3].size();i++) ans+=p[cnt[3][i]].c;
            }
            else
            {
                sort(cnt[3].begin(),cnt[3].end(),cmp3);
                for(int i=0;i<=n/2-1;i++) ans+=p[cnt[3][i]].c;
                for(int i=n/2;i<cnt[3].size();i++) ans+=p[cnt[3][i]].b;
                for(int i=0;i<cnt[2].size();i++) ans+=p[cnt[2][i]].b;
            }
        }
        else if(cnt[2].size()>n/2)
        {
            sort(cnt[2].begin(),cnt[2].end(),cmp2);
            for(int i=0;i<=n/2-1;i++) ans+=p[cnt[2][i]].b;
            for(int i=n/2;i<cnt[2].size();i++)
            {
                p[i].b=0;
                if(p[i].a>=p[i].c) cnt[1].push_back(p[i].id);
                else cnt[3].push_back(p[i].id);
            }
            if(cnt[1].size()<=n/2&&cnt[3].size()<=n/2)
            {
                for(int i=0;i<cnt[1].size();i++) ans+=p[cnt[1][i]].a;
                for(int i=0;i<cnt[3].size();i++) ans+=p[cnt[3][i]].c;
            }
            else if(cnt[1].size()>n/2)
            {
                sort(cnt[1].begin(),cnt[1].end(),cmp1);
                for(int i=0;i<n/2;i++) ans+=p[cnt[1][i]].a;
                for(int i=n/2;i<cnt[1].size();i++) ans+=p[cnt[1][i]].c;
                for(int i=0;i<cnt[3].size();i++) ans+=p[cnt[3][i]].c;
            }
            else
            {
                sort(cnt[3].begin(),cnt[3].end(),cmp3);
                for(int i=0;i<n/2;i++) ans+=p[cnt[3][i]].c;
                for(int i=n/2;i<cnt[3].size();i++) ans+=p[cnt[3][i]].a;
                for(int i=0;i<cnt[1].size();i++) ans+=p[cnt[1][i]].a;
            }
        }
        else if(cnt[3].size()>n/2)
        {
            sort(cnt[3].begin(),cnt[3].end(),cmp3);
            for(int i=0;i<n/2;i++) ans+=p[cnt[3][i]].c;
            for(int i=n/2;i<cnt[3].size();i++)
            {
                p[i].c=0;
                if(p[i].a>=p[i].b) cnt[1].push_back(p[i].id);
                else cnt[2].push_back(p[i].id);
            }
            if(cnt[1].size()<=n/2&&cnt[2].size()<=n/2)
            {
                for(int i=0;i<cnt[1].size();i++) ans+=p[cnt[1][i]].a;
                for(int i=0;i<cnt[2].size();i++) ans+=p[cnt[2][i]].c;
            }
            else if(cnt[1].size()>n/2)
            {
                sort(cnt[1].begin(),cnt[1].end(),cmp1);
                for(int i=0;i<n/2;i++) ans+=p[cnt[1][i]].a;
                for(int i=n/2;i<cnt[1].size();i++) ans+=p[cnt[1][i]].b;
                for(int i=0;i<cnt[2].size();i++) ans+=p[cnt[2][i]].b;
            }
            else
            {
                sort(cnt[2].begin(),cnt[2].end(),cmp2);
                for(int i=0;i<n/2;i++) ans+=p[cnt[2][i]].b;
                for(int i=n/2;i<cnt[2].size();i++) ans+=p[cnt[2][i]].a;
                for(int i=0;i<cnt[1].size();i++) ans+=p[cnt[1][i]].a;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
