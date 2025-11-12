#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=100005;

ll T,n;

bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.first>b.first;
}


int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin >> T;



    while(T--)
    {
        ll ans=0,cnt=0,fi=0,si=0,ti=0,cntf=0,cnts=0,cntt=0;
        cin >> n;
        vector<bool> bl(n+1,true);

        vector<pair<ll,ll>> f,s,t;
        ll a[maxn][10];
        for(int i=1;i<=n;i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            f.push_back({a[i][1],i});
            s.push_back({a[i][2],i});
            t.push_back({a[i][3],i});
        }


        sort(f.begin(),f.end());
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());


        for(int i=0;i<n;i++) f[i].first=f[i].first-a[f[i].second][2]-a[f[i].second][3];
        for(int i=0;i<n;i++) s[i].first=s[i].first-a[s[i].second][1]-a[s[i].second][3];
        for(int i=0;i<n;i++) t[i].first=t[i].first-a[t[i].second][1]-a[t[i].second][2];

        sort(f.begin(),f.end(),cmp);
        sort(s.begin(),s.end(),cmp);
        sort(t.begin(),t.end(),cmp);


        while(cnt!=n)
        {

            if(cnt==0)
            {
                if(f[0].second==s[0].second)
                {
                    ans+=max(a[f[0].second][1],a[s[0].second][2]);
                    if(max(a[f[0].second][1],a[s[0].second][2])==a[f[0].second][1])
                    {
                        cntf++;
                        bl[f[0].second]=false;
                    }
                    else
                    {
                        cnts++;
                        bl[f[0].second]=false;
                    }
                    cnt++;
                }
                if(f[0].second==t[0].second)
                {
                    ans+=max(a[f[0].second][1],a[t[0].second][3]);
                    if(max(a[f[0].second][1],a[s[0].second][2])==a[f[0].second][1])
                    {
                        cntf++;
                        bl[f[0].second]=false;
                    }
                    else
                    {
                        cntt++;
                        bl[f[0].second]=false;
                    }
                    cnt++;

                }
                if(s[0].second==t[0].second)
                {
                    ans+=max(a[s[0].second][2],a[t[0].second][3]);
                    if(max(a[s[0].second][2],a[t[0].second][3])==a[s[0].second][2])
                    {
                        cnts++;
                        bl[s[0].second]=false;
                    }
                    else
                    {
                        cntt++;
                        bl[s[0].second]=false;
                    }
                    cnt++;

                }
                if(ans==0)
                {
                    ans=ans+a[f[0].second][1]+a[s[0].second][2]+a[t[0].second][3];
                    cnt+=3;
                }
                continue;
            }


            while(bl[f[fi].second]==false&&fi<n) fi++;
            while(bl[s[si].second]==false&&si<n) si++;
            while(bl[t[ti].second]==false&&ti<n) ti++;

            if(n-cnt<3)
            {
                if(n-cnt==1)
                {
                    ll res;
                    res=max(f[fi].first,max(s[si].first,t[ti].first));

                    if(res==f[fi].first) ans+=a[f[fi].second][1];
                    if(res==s[si].first) ans+=a[s[si].second][1];
                    if(res==t[ti].first) ans+=a[t[ti].second][1];
                    break;
                }
                if(n-cnt==2)
                {
                    ll res;
                    res=max(f[fi].first,max(s[si].first,t[ti].first));
                    if(res==f[fi].first) ans+=a[f[fi].second][1];
                    if(res==s[si].first) ans+=a[s[si].second][2];
                    if(res==t[ti].first) ans+=a[t[ti].second][3];

                    if(res==f[fi].first)
                    {
                        ll res1;
                        res1=max(s[si].first,t[ti].first);
                        if(res1==s[si].first) ans+=a[s[si].second][2];
                        if(res1==t[ti].first) ans+=a[t[ti].second][3];
                        break;

                    }
                    if(res==s[si].first)
                    {
                        ll res1;
                        res1=max(f[fi].first,t[ti].first);
                        if(res1==f[fi].first) ans+=a[f[fi].second][1];
                        if(res1==t[ti].first) ans+=a[t[ti].second][3];
                        break;
                    }
                    if(res==t[ti].first)
                    {
                        ll res1;
                        res1=max(s[si].first,f[fi].first);
                        if(res1==s[si].first) ans+=a[s[si].second][2];
                        if(res1==f[fi].first) ans+=a[f[fi].second][1];
                        break;
                    }
                }
            }


            if(fi<n&&cntf<=n/2)
            {
                ans+=a[f[fi].second][1];
                cntf++;
                bl[f[fi].second]=false;
                cnt++;
            }

            if(si<n&&cnts<=n/2)
            {
                ans+=a[s[si].second][1];
                cnts++;
                bl[s[si].second]=false;
                cnt++;
            }

            if(ti<n&&cntt<=n/2)
            {
                ans+=a[t[ti].second][1];
                cntt++;
                bl[t[ti].second]=false;
                cnt++;
            }
        }

        cout << ans << endl;

    }



    return 0;
}
