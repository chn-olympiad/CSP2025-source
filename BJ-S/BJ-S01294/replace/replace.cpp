#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
};
int n,q,ans,pows[5000005],base = 131,mod = 998244353;
string a[200005],b[200005];
int hashsa[10005][10005],rhashsa[10005][10005],hashsb[10005][10005];
void get_pows()
{
    pows[0] = 1;
    for(int i = 1;i <= n;i++)
    {
        (pows[i] = pows[i-1]*base) %= mod;
    }
}
void get_hasha(int x)
{
    int sum = 0;
    for(int i = 0;i < a[x].size();i++)
    {
        (sum += pows[i] * a[x][i]) %= mod;
        hashsa[x][i] = sum;
    }
}
void get_rhasha(string s,int x)
{
    int sum = 0;
    for(int i = 0;i < s.size();i++)
    {
        (sum += pows[i] * s[i]) %= mod;
        rhashsa[x][i] = sum;
    }
}
void get_hashb(int x)
{
    int sum = 0;
    for(int i = 0;i < b[x].size();i++)
    {
        (sum += pows[i] * b[x][i]) %= mod;
        hashsb[x][i] = sum;
    }
}
int get_hash(string x)
{
    int sum = 0;
    for(int i = 0;i < x.size();i++)
    {
        (sum += pows[i] * x[i]) %= mod;
    }
    return sum;
}
bool has(int x,int y,int z)
{
    if(a[x].size() > b[y].size()) return false;
    if(a[x].size() == b[x].size())
    {

        if(hashsb[y][b[y].size()-1]%mod == hashsa[y][a[x].size()-1]%mod)
        {
            if(z == rhashsa[x][b[x].size()-1])
            {
                //cout<<x<<" "<<y<<" "<<z<<endl;
                ans++;
            }
            return true;
        }
        return false;
    }

    if((hashsb[y][b[y].size()-1]-hashsb[y][b[y].size()-a[x].size()-1]+mod)%mod == (hashsa[x][a[x].size()-1]*pows[b[y].size()-a[x].size()])%mod)
    {
        if(((hashsb[y][b[y].size()-1]-hashsb[y][b[y].size()-a[x].size()-1]+mod)%mod+(rhashsa[x][a[x].size()-1]*pows[b[y].size()-a[x].size()])+mod)%mod == z)
        {
            //cout<<x<<" "<<y<<" "<<z<<endl;
            ans++;
        }
        return true;
    }
    return false;
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    get_pows();
    for(int i = 1;i <= n;i++)
    {
        string x;
        cin>>a[i]>>x;
        get_hasha(i);
        get_rhasha(x,i);
    }
    for(int i = 1;i <= q;i++)
    {
        string x;
        cin>>b[i]>>x;
        get_hashb(i);
        for(int j = 1;j <= n;j++)
        {
            if(has(j,i,get_hash(x)))
            {
                ;//AWA
            }
        }
        cout<<ans<<endl;
        ans = 0;
    }
}
