#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
string s[N][2],t1,t2,f0,f1;
unsigned long long a[N][2],h[N],p[N];
unsigned long long cv(int l,int r)
{
    if(l>r) return 0;
    if(l==0) return h[r];
    return h[r]-h[l-1]*p[r-l+1];
}
int he[N];
unordered_map<string,unordered_map<string,int> > mp;
pair<int,int> len[N];
int sol(string t1,string t2)
{
    if(t1.size()!=t2.size()) return 0;
    int i,j,ans=0,l,r;
    string w1="",w2="";
    h[0]=t1[0]-'a'+1;
    for(j=1;j<t1.size();j++)
    {
        h[j]=h[j-1]*131+t1[j]-'a'+1;
    }
    for(i=0;i<t1.size();i++)
    {
        if(t1[i]!=t2[i])
        {
            l=i;
            break;
        }
    }
    for(i=t1.size()-1;i>=0;i--)
    {
        if(t1[i]!=t2[i])
        {
            r=i;
            break;
        }
    }
    for(i=l;i<=r;i++)
    {
        w1+=t1[i];
        w2+=t2[i];
    }
    int now=mp[w1][w2];
    if(now==0) return 0;
    // cerr<<w1<<" "<<w2<<"\n";
    // cerr<<now<<"\n";
    while(now)
    {
        // cerr<<now<<" "<<he[now]<<"!\n";
        if(l-len[now].first<0||r+s[now][0].size()-len[now].second-1>=t1.size())
        {
            now=he[now];
            continue;
        }
        // cout<<"len:"<<len[now].first<<" "<<len[now].second<<"\n";
        // cout<<"a:"<<a[now][0]<<" "<<a[now][1]<<"\n";
        // cout<<"le:"<<l-len[now].first<<" "<<l-1<<"\n";
        // cout<<"ri:"<<r+1<<" "<<r+s[now][0].size()-len[now].second-1<<"\n";
        if(a[now][0]==cv(l-len[now].first,l-1)&&a[now][1]==cv(r+1,r+s[now][0].size()-len[now].second-1))
        {
            ans++;
        }
        // cerr<<now<<" "<<he[now]<<"!\n";
        now=he[now];
    }
    return ans;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int i,j,k,n,m,l,r,x,y,o,ans=0;
    p[0]=1;
    for(i=1;i<=5000000;i++) p[i]=p[i-1]*131;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>s[i][0]>>s[i][1];
        if(s[i][0]==s[i][1])
        {
            len[i]={n+1,n+1};
            continue;
        }
        h[0]=s[i][0][0]-'a'+1;
        for(j=1;j<s[i][0].size();j++)
        {
            h[j]=h[j-1]*131+s[i][0][j]-'a'+1;
        }
        for(j=0;j<s[i][0].size();j++)
        {
            if(s[i][0][j]!=s[i][1][j])
            {
                break;
            }
        }
        len[i].first=j;
        l=j;
        for(j=s[i][0].size()-1;j>0;j--)
        {
            if(s[i][0][j]!=s[i][1][j])
            {
                break;
            }
        }
        len[i].second=j;
        r=j;
        f0="";
        f1="";
        for(j=len[i].first;j<=len[i].second;j++)
        {
            f0+=s[i][0][j];
            f1+=s[i][1][j];
        }
        he[i]=mp[f0][f1];
        mp[f0][f1]=i;
        a[i][0]=cv(0,l-1);
        a[i][1]=cv(r+1,s[i][0].size()-1);
    }
    for(i=1;i<=m;i++)
    {
        cin>>t1>>t2;
        cout<<sol(t1,t2)<<"\n";
    }
    return 0;
}