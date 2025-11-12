#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][3],n,cnt[N],ch[N];
int rech[N],len=0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--)
    {
        int s=0;
        memset(cnt,0,sizeof cnt);
        memset(rech,0,sizeof rech);
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++) cin>>a[i][j];
        }
        for(int i=0;i<n;i++)
        {
            int c=max_element(a[i],a[i]+3)-a[i];
            cnt[c]++;
            ch[i]=c;s+=a[i][c];
        }
        
        int hot=max_element(cnt,cnt+3)-cnt;
        len=0;
        for(int i=0;i<n;i++)
        {
            if(ch[i]==hot)
            {
                int d=0;
                if(hot==0) d=max(a[i][1],a[i][2]);
                if(hot==1) d=max(a[i][0],a[i][2]);
                if(hot==2) d=max(a[i][0],a[i][1]);
                d=a[i][hot]-d;
                rech[len++]=d;
            }
        }
        sort(rech,rech+len);
        for(int i=0;i<cnt[hot]-n/2;i++) s-=rech[i];
        cout<<s<<endl;
    }
    return 0;
}