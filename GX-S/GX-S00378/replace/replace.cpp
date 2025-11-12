#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#define ll long long
using namespace std;
const int N=15000006;
int n,q,mx,cnt;
int tr[N][26],sum[N];
string to[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    cnt=1;
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        int len=s1.size();
        mx=max(mx,len);
        int pos=1;
        for(int j=0;j<len;j++)
        {
            int id=s1[j]-'a';
            if(!tr[pos][id])
            {
                if(cnt>=N-5) break;
                tr[pos][id]=++cnt;
            }
            pos=tr[pos][id];
            //printf("pos=%d,tr[pos][id]=%d\n",pos,tr[pos][id]);fflush(stdout);
        //cout<<"cnt="<<cnt<<"\n";
        }
        to[pos]=s2,sum[pos]++;
    }
    while(q--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int l1=s1.size(),l2=s2.size();
        if(l1!=l2)
        {
            cout<<"0\n";
            continue;
        }
        int len=l1,l=-1,r=0;
        for(int i=0;i<len;i++)
            if(s1[i]!=s2[i])
            {
                if(l==-1) l=i;
                r=i;
            }
        if(r-l+1>mx)
        {
            cout<<"0\n";
            continue;
        }
        string t2=s2.substr(l,r-l+1);
        int ans=0;
        while(l>=0)
        {
            string now=t2;
            int pos=1,f=1;
            for(int i=l;i<=r;i++)
                if(tr[pos][s1[i]-'a']) pos=tr[pos][s1[i]-'a'];
                else
                {
                    f=0;
                    break;
                }
            if(f)
                for(int i=r;i<len;i++)
                {
                    if(to[pos]==now) ans+=sum[pos];
                    if(i+1<len)
                    {
                        pos=tr[pos][s2[i+1]-'a'];
                        if(!pos) break;
                        now+=s2[i+1];
                    }
                }
            l--;
            if(l>=0) t2=s2[l]+t2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
