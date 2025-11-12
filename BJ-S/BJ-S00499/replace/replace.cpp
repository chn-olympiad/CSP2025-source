#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
const int maxn=2e5+10,maxm=5e6+10;
const ll Q=103,mod=998244853;
int n,q;
ll power[maxm];
ll hs1[maxn],hs2[maxn];
string s1[maxn],s2[maxn],t1[maxn],t2[maxn];
int len[maxn],c;
unordered_map<ll,int> b;
ll calc1(int l,int r)
{
    if(l==0) return hs1[r];
    return (hs1[r]-hs1[l-1]*power[r-l+1]%mod+mod)%mod;
}
ll calc2(int l,int r)
{
    if(l==0) return hs2[r];
    return (hs2[r]-hs2[l-1]*power[r-l+1]%mod+mod)%mod;
}
/*
struct solsp
{
    bool chk()
    {
        for(int i=1;i<=n;i++)
        {
            int cnt1=0,cnt2=0;
            for(int j=0;j<s1[i].size();j++)
            {
                if(s1[i][j]!='a'&&s1[i][j]!='b') return 0;
                if(s2[i][j]!='a'&&s2[i][j]!='b') return 0;
                if(s1[i][j]=='b')
                {
                    cnt++;
                    if(cnt>1) return 0;
                }
            }
        }
    }
    void sol()
    {

    }
};
*/
map<pii,int> b2;
void solbr()
{
    for(int i=1;i<=q;i++)
    {
        int tlen=t1[i].size();
        if(tlen!=(int)t2[i].size())
        {
            cout<<0<<endl;
            continue;
        }
        int st=-1,ed=-1;
        for(int j=0;j<tlen;j++)
        {
            if(t1[i][j]!=t2[i][j])
            {
                if(st<0) st=j;
                ed=j;
            }
        }
        hs1[tlen]=hs2[tlen]=0;
        hs1[0]=t1[i][0]-'a'+1;
        for(int j=1;j<tlen;j++) hs1[j]=(hs1[j-1]*Q+t1[i][j]-'a'+1)%mod;
        hs2[0]=t2[i][0]-'a'+1;
        for(int j=1;j<tlen;j++) hs2[j]=(hs2[j-1]*Q+t2[i][j]-'a'+1)%mod;
        int t=ed-st+1;
        int p=lower_bound(len+1,len+1+c,t)-len;
        int res=0;
        //cout<<"test: "<<t<<endl;
        for(int j=p;j<=c;j++)
        {
            int l=st-(len[j]-t),r=ed+(len[j]-t)-len[j]+1;
            //cout<<l<<" "<<r<<endl;
            for(int k=l;k<=r;k++)
            {
                if(k<0) continue;
                if(k+len[j]-1>=tlen) break;
                res+=b2[mp(calc1(k,k+len[j]-1),calc2(k,k+len[j]-1))];
            }
        }
        cout<<res<<endl;
    }
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    power[0]=1;
    for(int i=1;i<=5e6;i++) power[i]=power[i-1]*Q%mod;
    int slen1=0,slen2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        ll t1=0,t2=0;
        int tmp=s1[i].size();
        for(int j=0;j<tmp;j++) t1=(t1*Q+s1[i][j]-'a'+1)%mod;
        for(int j=0;j<tmp;j++) t2=(t2*Q+s2[i][j]-'a'+1)%mod;
        len[i]=tmp;
        slen1+=tmp;
        //cout<<t1<<" "<<t2<<endl;
        b[1ll*t1*1e9+t2]++;
        b2[mp(t1,t2)]++;
    }
    sort(len+1,len+1+n),c=unique(len+1,len+1+n)-len-1;
    for(int i=1;i<=q;i++) cin>>t1[i]>>t2[i],slen2+=t1[i].size();

    if(slen1<=2e5&&slen2<=2e5)
    {
        solbr();
        return 0;
    }
    for(int i=1;i<=q;i++)
    {
        int tlen=t1[i].size();

        if(tlen!=(int)t2[i].size())
        {
            cout<<0<<endl;
            continue;
        }
        int st=-1,ed=-1;
        for(int j=0;j<tlen;j++)
        {
            if(t1[i][j]!=t2[i][j])
            {
                if(st<0) st=j;
                ed=j;
            }
        }
        hs1[tlen]=hs2[tlen]=0;
        hs1[0]=t1[i][0]-'a'+1;
        for(int j=1;j<tlen;j++) hs1[j]=(hs1[j-1]*Q+t1[i][j]-'a'+1)%mod;
        hs2[0]=t2[i][0]-'a'+1;
        for(int j=1;j<tlen;j++) hs2[j]=(hs2[j-1]*Q+t2[i][j]-'a'+1)%mod;
        int t=ed-st+1;
        int p=lower_bound(len+1,len+1+c,t)-len;
        int res=0;
        //cout<<"test: "<<t<<endl;
        for(int j=p;j<=c;j++)
        {
            int l=st-(len[j]-t),r=ed+(len[j]-t)-len[j]+1;
            //cout<<l<<" "<<r<<endl;
            for(int k=l;k<=r;k++)
            {
                if(k<0) continue;
                if(k+len[j]-1>=tlen) break;
                res+=b[1ll*calc1(k,k+len[j]-1)*1e9+calc2(k,k+len[j]-1)];
            }
        }
        cout<<res<<endl;
    }
//    cout<<slen1<<" "<<slen2<<endl;
//    fclose(stdout);
	return 0;
}
