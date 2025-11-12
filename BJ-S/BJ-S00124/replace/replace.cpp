#include <iostream>
#include <vector>
#include <map>
using namespace std;
constexpr int N=2e5+3,base=131,L=5e6+3;
typedef unsigned long long ull;
string s1[N],s2[N];
vector<ull> hshs1[N],hshs2[N];
ull powe[L];
vector<ull> hsht1,hsht2;
ull gethsh(vector<ull> hsh[],int i,int l,int r)
{
    if (l==0)
    {
        return hsh[i][r];
    }
    //cout<<hsh[i][l-1]*powe[r-l+1]<<'\n';
    return hsh[i][r]-hsh[i][l-1]*powe[r-l+1];
}
ull gethsh(vector<ull> &hsh,int l,int r)
{
    if (l==0)
    {
        return hsh[r];
    }
    return hsh[r]-hsh[l-1]*powe[r-l+1];
}
int lcp(string &t1,string &t2)
{
    int l=1,r=min(t1.size(),t2.size());
    while (l<r)
    {
        int mid=l+r+1>>1;
        if (gethsh(hsht1,0,mid-1)==gethsh(hsht2,0,mid-1))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    if (gethsh(hsht1,0,l-1)!=gethsh(hsht2,0,l-1)) l--;
    return l;
}
int lcs(string &t1,string &t2)
{
    int l=1,r=min(t1.size(),t2.size());
    while (l<r)
    {
        int mid=l+r+1>>1;
        if (gethsh(hsht1,t1.size()-mid,t1.size()-1)==gethsh(hsht2,t2.size()-mid,t2.size()-1))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    if (gethsh(hsht1,t1.size()-l,t1.size()-1)!=gethsh(hsht2,t2.size()-l,t2.size()-1)) l--;
    return l;
}
map<pair<ull,ull>,int> m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    powe[0]=1;
    for (int i=1;i<L;i++)
    {
        powe[i]=powe[i-1]*base;
    }
    for (int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        hshs1[i].reserve(s1[i].size());
        hshs2[i].reserve(s2[i].size());
        for (int j=0;j<s1[i].size();j++)
        {
            if (j!=0) hshs1[i].push_back(hshs1[i].back()*base+ull(s1[i][j]-'a'+1));
            else hshs1[i].push_back(ull(s1[i][j]-'a'+1));
            //cout<<i<<' '<<j<<' '<<hshs1[i][j]<<'\n';
        }
        for (int j=0;j<s2[i].size();j++)
        {
            if (j!=0) hshs2[i].push_back(hshs2[i].back()*base+ull(s2[i][j]-'a'+1));
            else hshs2[i].push_back(ull(s2[i][j]-'a'+1));
        }
        //cout<<gethsh(hshs1,i,s1[i].size()-1,s1[i].size()-1)<<' '<<gethsh(hshs2,i,s2[i].size()-1,s2[i].size()-1)<<'\n';
        m[{gethsh(hshs1,i,0,s1[i].size()-1),gethsh(hshs2,i,0,s2[i].size()-1)}]++;
    }
    while (q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        if (t1.size()!=t2.size())
        {
            cout<<"0\n";
            continue;
        }
        hsht1.clear();
        hsht2.clear();
        hsht1.reserve(t1.size());
        hsht2.reserve(t2.size());
        for (int j=0;j<t1.size();j++)
        {
            //cout<<hsht1.back()<<'\n';
            if (j!=0) hsht1.push_back(hsht1.back()*base+ull(t1[j]-'a'+1));
            else hsht1.push_back(ull(t1[j]-'a'+1));
            //cout<<j<<' '<<hsht1.back()<<'\n';

        }
        for (int j=0;j<t2.size();j++)
        {
            if (j!=0) hsht2.push_back(hsht2.back()*base+ull(t2[j]-'a'+1));
            else hsht2.push_back(ull(t2[j]-'a'+1));
        }
        int lcpp=lcp(t1,t2);
        int lcss=lcs(t1,t2);
        int ans=0;
        //cout<<"lcp:"<<lcpp<<' '<<"lcs:"<<lcss<<'\n';
        //cout<<"last:"<<gethsh(hsht1,t1.size()-1,t1.size()-1)<<'\n';
        for (int r=t1.size();(int)t1.size()-r-1<lcss;r--)
        {
            int l=-1;
            while (l+1<r&&l<lcpp)
            {
                ull aimx=gethsh(hsht1,l+1,r-1),aimy=gethsh(hsht2,l+1,r-1);
                //cout<<l+1<<' '<<r-1<<' '<<aimx<<' '<<aimy<<'\n';
                if (m.count({aimx,aimy}))
                {
                    ans+=m[{aimx,aimy}];
                }
                l++;
            }
        }
        /*
        if (m.count({gethsh(hsht1,0,hsht1.size()-1),gethsh(hsht2,0,hsht2.size()-1)}))
        {
            ans+=m[{gethsh(hsht1,0,hsht1.size()-1),gethsh(hsht2,0,hsht2.size()-1)}];
        }*/
        cout<<ans<<'\n';
    }
}
