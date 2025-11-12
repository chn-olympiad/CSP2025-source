#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll m1=998244357;
const ll m2=1e9+7;
const ll base=233;
const int N=2e5+5;
const int L=5e6+5;
int n,q;
string s1[N],s2[N],t1,t2;
ll hs1[L],h1[N],h2[N],ht1[L],p1[L];
unordered_map<int,unordered_map<int,int> > mp;
unordered_map<int,int> cnt;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    p1[0]=1;
    for(int i=1;i<L;i++)    p1[i]=(p1[i-1]*base)%m1;
    for(int k=1;k<=n;k++)
    {
        cin>>s1[k]>>s2[k];
        hs1[0]=(s1[k][0]-'a'+1);
        ht1[0]=(s2[k][0]-'a'+1);
        for(int j=1;j<s1[k].size();j++)
        {
            hs1[j]=(hs1[j-1]*base+(s1[k][j]-'a'+1))%m1;

            ht1[j]=(ht1[j-1]*base+(s2[k][j]-'a'+1))%m1;
        }
        int len=s1[k].size();
        mp[hs1[len-1]][ht1[len-1]]++;
        h1[k]=hs1[len-1];
        h2[k]=ht1[len-1];
        /*
        for(int i=0;i<s1[k].size();i++)
        {
            for(int j=i;j<s1[k].size();j++)
            {
                    if(i)
                        mp[(hs1[j]-hs1[i-1]*p1[j-i+1]%m1+m1)%m1][(ht1[j]-ht1[i-1]*p1[j-i+1]%m1+m1)%m1]++;
                    else
                    {
                 //       cout<<"ini"<<hs1[j]<<' '<<ht1[j]<<'\n';
                        mp[hs1[j]][ht1[j]]++;
                    }
            }
        }
        */
    }

    while(q--)
    {
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
        {
            cout<<"0\n";
        }
        else
        {
            ll ans=0;
            int len=t1.size();
            int pre=-1,suf=len;
            for(int j=0;j<len;j++)
            {
                if(t1[j]==t2[j])    pre=j;
                else    break;
            }
            for(int j=len-1;j>=0;j--)
            {
                if(t1[j]==t2[j])    suf=j;
                else    break;
            }
            hs1[0]=(t1[0]-'a'+1);
            ht1[0]=(t2[0]-'a'+1);
            for(int j=1;j<len;j++)
            {
                hs1[j]=(hs1[j-1]*base+(t1[j]-'a'+1))%m1;
                ht1[j]=(ht1[j-1]*base+(t2[j]-'a'+1))%m1;
            }
            //j+s1[i].size()>=suf
            for(int i=1;i<=n;i++)
            {
                int l=s1[i].size();
                for(int j=max(0,suf-l);j<len+1-l&&j<=pre+1;j++)
                {
                    if(j)
                    {
                        if((hs1[j+l-1]-hs1[j-1]*p1[l]%m1+m1)%m1==h1[i])
                        {
                            if(h2[i]==(ht1[j+l-1]-ht1[j-1]*p1[l]%m1+m1)%m1) ans++;
                        }
                    }
                    else
                    {
                        if(hs1[j+l-1]==h1[i]&&ht1[j+l-1]==h2[i])    ans++;
                    }
                }
            }
            cout<<ans<<'\n';
        }
    }

    return 0;
}
