#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1[200005],t2[200005];
typedef unsigned long long ull;
pair<ull,int> hs[200005],ht[200005];
int hsn,htn;
int ls[200005],rs[200005],lt[200005],rt[200005];
vector<ull> htl[200005],htr[200005];
ull hsl[200005],hsr[200005];
int an[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t1[i]>>t2[i];
    }
    for(int i=1;i<=n;i++)
    {
        int l=s1[i].length();
        ls[i]=-1;
        for(int j=0;j<l;j++)
        {
            if(s1[i][j]!=s2[i][j])
            {
                ls[i]=j;
                break;
            }
        }
        if(ls[i]==-1)
            continue;
        for(int j=l-1;j>=0;j--)
        {
            if(s1[i][j]!=s2[i][j])
            {
                rs[i]=j;
                break;
            }
        }
        hsn++;
        hs[i].second=i;
        hs[i].first=0;
        for(int j=ls[i];j<=rs[i];j++)
        {
            hs[i].first=hs[i].first*131+s1[i][j];
        }
        ull xum=0;
        for(int j=ls[i]-1;j>=0;j--)
        {
            xum=xum*131+s1[i][j];
        }
        hsl[i]=xum;
        xum=0;
        for(int j=rs[i]+1;j<l;j++)
        {
            xum=xum*131+s1[i][j];
        }
        hsr[i]=xum;
    }
    for(int i=1;i<=q;i++)
    {
        int l=t1[i].length();
        if(l!=t2[i].length())
            break;
        lt[i]=-1;
        for(int j=0;j<l;j++)
        {
            if(t1[i][j]!=t2[i][j])
            {
                lt[i]=j;
                break;
            }
        }
        if(lt[i]==-1)
            continue;
        for(int j=l-1;j>=0;j--)
        {
            if(t1[i][j]!=t2[i][j])
            {
                rt[i]=j;
                break;
            }
        }
        htn++;
        ht[i].second=i;
        ht[i].first=0;
        for(int j=lt[i];j<=rt[i];j++)
        {
            ht[i].first=ht[i].first*131+t1[i][j];
        }

        ull xum=0;
        for(int j=lt[i]-1;j>=0;j--)
        {
            xum=xum*131+t1[i][j];
            htl[i].push_back(xum);
        }
        xum=0;
        for(int j=rt[i]+1;j<l;j++)
        {
            xum=xum*131+t1[i][j];
            htr[i].push_back(xum);
        }
    }
    sort(hs+1,hs+hsn+1);
    sort(ht+1,ht+htn+1);
    int hsp=1,htp=1;
    while(hsp<=hsn && htp<=htn)
    {
        if(hs[hsp].first>ht[htp].first)
        {
            while(htp<=htn && hs[hsp].first>ht[htp].first)
                htp++;
            if(htp>htn)
                break;
        }
        else if(hs[hsp].first<ht[htp].first)
        {
            while(hsp<=hsn && hs[hsp].first<ht[htp].first)
                hsp++;
            if(hsp>hsn)
                break;
        }
        if(hs[hsp].first==ht[htp].first)
        {
            int hspr=hsp,htpr=htp;
            while(hspr<=hsn && hs[hspr].first==hs[hsp].first)
                hspr++;
            hspr--;
            while(htpr<=htn && ht[htpr].first==ht[htp].first)
                htpr++;
            htpr--;
            for(int i=hsp;i<=hspr;i++)
            {
                int lid=ls[hs[i].second]-1;
                int rid=s1[hs[i].second].length()-rs[hs[i].second]-2;
               // cout<<hs[i].second<<"  ";
                ull lwt=hsl[hs[i].second];
                ull rwt=hsr[hs[i].second];
               // cout<<lid<<" "<<rid<<" "<<lwt<<" "<<rwt<<"\n";
                for(int j=htp;j<=htpr;j++)
                {
                    if(lid==-1 || htl[ht[j].second].size()>lid && htl[ht[j].second][lid]==lwt)
                    {
                        if(rid==-1 || htr[ht[j].second].size()>rid && htr[ht[j].second][rid]==rwt)
                        {
                            an[ht[j].second]++;
                        }
                    }
                }
            }
          //  cout<<hsp<<" "<<hspr<<" "<<htp<<" "<<htpr<<"\n";
            hsp=hspr+1,htp=htpr+1;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cout<<an[i]<<"\n";
    }
    return 0;
}
