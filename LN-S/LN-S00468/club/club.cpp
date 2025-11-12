#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10,D=2e4+10;
int a[3],b[3],cnt[3],ind[3];
pair<pair<int,int>,pair<pair<int,int>,int> > d[N];
vector<pair<pair<int,int>,pair<pair<int,int>,int> > > v[3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        v[0].clear();
        v[1].clear();
        v[2].clear();
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(cnt,0,sizeof cnt);
        memset(ind,0,sizeof ind);
        int ans=0,n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[0]>>a[1]>>a[2];
            b[0]=a[0];
            b[1]=a[1];
            b[2]=a[2];
            sort(b,b+3);
            reverse(b,b+3);
            if(b[0]==a[0])d[i].second.first.first=0;
            else if(b[0]==a[1])d[i].second.first.first=1;
            else d[i].second.first.first=2;
            if(b[1]==a[0])d[i].second.first.second=0;
            else if(b[1]==a[1])d[i].second.first.second=1;
            else d[i].second.first.second=2;
            if(b[2]==a[0])d[i].second.second=0;
            else if(b[2]==a[1])d[i].second.second=1;
            else d[i].second.second=2;
            d[i].first.first=b[0]-b[1];
            d[i].second.second=b[1]-b[2];
            cnt[d[i].second.first.first]++;
            ans+=b[0];
            if(d[i].second.first.first==0)v[0].push_back(d[i]);
            else if(d[i].second.first.first==1)v[1].push_back(d[i]);
            else v[2].push_back(d[i]);
        }
        if(*max_element(cnt,cnt+3)<=n/2)
        {
            cout<<ans;
        }
        else
        {
            if(cnt[0]==*max_element(cnt,cnt+3))ind[0]=0;
            else if(cnt[1]==*max_element(cnt,cnt+3))ind[0]=1;
            else ind[0]=2;
            if(cnt[0]==*min_element(cnt,cnt+3))ind[2]=0;
            else if(cnt[1]==*min_element(cnt,cnt+3))ind[2]=1;
            else ind[2]=2;
            ind[1]=3-ind[0]-ind[2];
            sort(v[ind[0]].begin(),v[ind[0]].end());
            while(cnt[ind[0]]>n/2)
            {
                ans-=v[ind[0]][0].first.first;
                swap(v[ind[0]][0].first.first,v[ind[0]][0].first.second);
                v[ind[0]][0].first.second=(-1)*v[ind[0]][0].first.second;
                swap(v[ind[0]][0].second.first.second,v[ind[0]][0].second.second);
                v[v[ind[0]][0].second.first.second].push_back(v[ind[0]][0]);
                v[ind[0]].erase(v[ind[0]].begin());
                cnt[ind[0]]--;
                cnt[v[ind[0]][0].second.first.second]++;
            }
            if(*max_element(cnt,cnt+3)<=n/2)cout<<ans;
            else
            {
                if(cnt[0]==*max_element(cnt,cnt+3))ind[0]=0;
                else if(cnt[1]==*max_element(cnt,cnt+3))ind[0]=1;
                else ind[0]=2;
                if(cnt[0]==*min_element(cnt,cnt+3))ind[2]=0;
                else if(cnt[1]==*min_element(cnt,cnt+3))ind[2]=1;
                else ind[2]=2;
                ind[1]=3-ind[0]-ind[2];
                int mind=D,mind2=D;
                for(auto x:v[ind[0]])
                {
                    if(x.second.first.second==ind[2])mind=min(mind,x.first.first),mind2=min(mind2,x.first.second);
                    else mind=min(mind,x.first.second),mind2=min(mind2,x.first.first);
                }
                for(auto x:v[ind[1]])
                {
                    mind=min(mind,mind2+x.first.first+x.first.second);
                }
                ans-=mind;
                cout<<ans;
            }
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
