#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int adj1[N],adj2[N],adj3[N];
int cnt1,cnt2,cnt3;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    int a,b,c;
    while(T--)
    {
        memset(adj1,0,sizeof adj1);
        memset(adj2,0,sizeof adj2);
        memset(adj3,0,sizeof adj3);
        cnt1=cnt2=cnt3=0;
        int n;
        cin>>n;
        int mx;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>c>>b;
            mx=max(a,max(b,c));
            if(mx==a)
            {
                ans+=a;
                if(b>=c) adj1[++cnt1]=a-b;
                else adj1[++cnt1]=a-c;
            }
            else if(mx==b)
            {
                ans+=b;
                if(a>=c) adj2[++cnt2]=b-a;
                else adj2[++cnt2]=b-c;
            }
            else
            {
                ans+=c;
                if(a>=b) adj3[++cnt3]=c-a;
                else adj3[++cnt3]=c-b;
            }
        }
        //cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<ans<<endl;
        //cout<<endl;
        if(cnt1*2>n)
        {
            //cout<<"1:"<<endl;
            sort(adj1+1,adj1+1+cnt1);
            //for(int i=1;i<=cnt1;i++) cout<<adj[1][i]<<" ";
            //cout<<endl;
            for(int i=1;cnt1-i>=n/2;i++) ans-=adj1[i];
        }
        if(cnt2*2>n)
        {
            //cout<<"2:"<<endl;
            sort(adj2+1,adj2+1+cnt2);
            //for(int i=1;i<=cnt2;i++) cout<<adj[2][i]<<" ";
            //cout<<endl;
            for(int i=1;cnt2-i>=n/2;i++) ans-=adj2[i];
        }
        if(cnt3*2>n)
        {
            //cout<<"3:"<<endl;
            sort(adj3+1,adj3+1+cnt3);
            //for(int i=1;i<=cnt3;i++) cout<<adj[3][i]<<" ";
            //cout<<endl;
            for(int i=1;cnt3-i>=n/2;i++) ans-=adj3[i];
        }
        cout<<ans<<endl;
    }
}

