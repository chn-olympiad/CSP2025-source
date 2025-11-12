#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string t1,t2;
int n,q;
struct cha
{
    string s1,s2;
    int c;
}cha[N];
int ans=0;
void dfs(int i,int w,int now)
{
    if(i>n)
    {
        if(now==w)
            ans++;
    }
    else
    {
        dfs(i+1,w,now+cha[i].c);
        dfs(i+1,w,now);
    }
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        cin >> cha[i].s1 >> cha[i].s2;
        int b1=0,b2=0;
        for(int j=0;j<cha[i].s1.size();j++)
        {
            if(cha[i].s1[j]=='b')
                b1=j;
        }
        for(int j=0;j<cha[i].s2.size();j++)
        {
            if(cha[i].s2[j]=='b')
                b2=j;
        }
        cha[i].c=b2-b1;
        //cout << cha[i].c << endl;
    }
    while(q--)
    {
        cin >> t1 >> t2;
        ans=0;
        int b1,b2;
        for(int i=0;i<t1.size();i++)
        {
            if(t1[i]=='b')
            {
                b1=i;
            }
        }
        for(int i=0;i<t2.size();i++)
        {
            if(t2[i]=='b')
            {
                b2=i;
            }
        }
        //cout << b2-b1 << endl;
        dfs(1,b2-b1,0);
        cout << ans;
    }
    return 0;
}
