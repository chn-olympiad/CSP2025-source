#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int N=2e5+233,S=5e6+233;
const ull b1=131,m1=1e16+2013,b2=331,m2=1e16+4033;
int n,m;
string s[N];
ull hs1[N],hs2[N],ht1[S],ht2[S];
ull b1p[S],b2p[S];
vector<int> nxt[N];


int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);

    cin>>n>>m;
    b1p[0]=b2p[0]=1;
    for (int i=1;i<S;i++)
        b1p[i]=b1p[i-1]*b1%m1,b2p[i]=b2p[i-1]*b2%m2;
    for (int i=1;i<=n;i++)
    {
        string s1;
        cin>>s1>>s[i];
        for (int j=0;j<s1.size();j++)
            hs1[i]=(hs1[i]*b1+s1[j])%m1,
            hs2[i]=(hs2[i]*b2+s1[j])%m2;
        nxt[i].resize(s[i].size()+1,0);
        for (int j=0,k=0;j<s[i].size();j++)
        {
            while (k&&s[i][k]!=s[i][j]) k=nxt[i][k];
            if (s[i][k]==s[i][j]) k++;
            nxt[i][j]=k;
        }
    }
    for (int i=1;i<=m;i++)
    {
        string t1,t2;
        cin>>t1>>t2;
        ht1[0]=ht2[0]=0;
        for (int j=1;j<=t1.size();j++)
            ht1[j]=(ht1[j-1]*b1+t1[j-1])%m1,
            ht2[j]=(ht2[j-1]*b2+t2[j-1])%m2;
        int l=0;
        while (l<t1.size())
            if (t1[l]==t2[l]) l++;
            else break;
        int r=t1.size()-1;
        while (r>=0)
            if (t1[r]==t2[r]) r--;
            else break;
        int ans=0;
        for (int j=1;j<=n;j++)
        {
            for (int k=0,l=0;k<t2.size();k++)
            {
                while (l&&s[j][l]!=t2[k]) l=nxt[j][l];
                if (s[j][l]==t2[k]) l++;
                if (l==s[j].size()&&(r<0||l>k||r<k-l+1)&&
                    (ht1[k+1]-ht1[k-l+1]*b1p[l]%m1+m1)%m1==hs1[j]&&
                    (ht2[k+1]-ht2[k-l+1]*b2p[l]%m2+m2)%m2==hs2[j]) ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
