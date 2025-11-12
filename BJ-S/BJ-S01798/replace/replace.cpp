#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 5e6 + 5;
string s1,s2,t1,t2;
int id,lens[200001],cnt1 = 1,cnt2 = 1;
int sons1[N][26],sons2[N][26],fail1[N],fail2[N];
vector<int> end1[N],end2[N];
inline void build1(int x,int p)
{
    if(p == lens[id])
    {
        end1[x].push_back(id);
        return;
    }
    if(!sons1[x][s1[p]-'a']) sons1[x][s1[p]-'a'] = ++cnt1;
    build1(sons1[x][s1[p]-'a'],p+1);
}
inline void build2(int x,int p)
{
    if(p == lens[id])
    {
        end2[x].push_back(id);
        return;
    }
    if(!sons2[x][s2[p]-'a']) sons2[x][s2[p]-'a'] = ++cnt2;
    build2(sons2[x][s2[p]-'a'],p+1);
}
queue<int> q;
inline void getfail1()
{
    q.push(1);
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        for(int i = 0;i < 26;i++)
            if(sons1[x][i])
            {
                int tmp = fail1[x];
                while(tmp && !sons1[tmp][i]) tmp = fail1[tmp];
                fail1[sons1[x][i]] = sons1[tmp][i];
                q.push(sons1[x][i]);
            }
    }
}
inline void getfail2()
{
    q.push(1);
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        for(int i = 0;i < 26;i++)
            if(sons2[x][i])
            {
                int tmp = fail2[x];
                while(tmp && !sons2[tmp][i]) tmp = fail2[tmp];
                fail2[sons2[x][i]] = sons2[tmp][i];
                q.push(sons2[x][i]);
            }
    }
}
bool ok[200001];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q; cin >> n >> q;
    for(id = 1;id <= n;id++)
    {
        cin >> s1 >> s2;
        lens[id] = s1.length();
        build1(1,0); build2(1,0);
    }
    fail1[1] = fail2[1] = 0;
    for(int i = 0;i < 26;i++) sons1[0][i] = sons2[0][i] = 1;
    getfail1(); getfail2();
    for(int i = 1;i <= q;i++)
    {
        cin >> t1 >> t2;
        if(t1.length() != t2.length())
        {
            puts("0");
            continue;
        }
        int lent = t1.length();
        int cur1 = 1,cur2 = 1,cur1p,cur2p,lstx,fstx = -1;
        long long ans = 0;
        for(int j = 0;j < lent;j++)
            if(t1[j] != t2[j])
            {
                lstx = j;
                if(fstx < 0) fstx = j;
            }
        for(int j = 0;j < lent;j++)
        {
            if(sons1[cur1][t1[j]-'a']) cur1 = sons1[cur1][t1[j]-'a'];
            else
            {
                while(cur1 && !sons1[cur1][t1[j]-'a']) cur1 = fail1[cur1];
                cur1 = sons1[cur1][t1[j]-'a'];
            }
            if(sons2[cur2][t2[j]-'a']) cur2 = sons2[cur2][t2[j]-'a'];
            else
            {
                while(cur2 && !sons2[cur2][t2[j]-'a']) cur2 = fail2[cur2];
                cur2 = sons2[cur2][t2[j]-'a'];
            }
            // cout << cur1 << " " << cur2 << endl;
            if(j < lstx || cur1 == 1 || cur2 == 1) continue;
            cur1p = cur1; cur2p = cur2;
            while(cur1 != 1)
            {
                for(int k = 0;k < end1[cur1].size();k++)
                {
                    // cout << "ok" << end1[cur1][k] << endl;
                    ok[end1[cur1][k]] = 1;
                }
                cur1 = fail1[cur1];
            }
            while(cur2 != 1)
            {
                for(int k = 0;k < end2[cur2].size();k++)
                {
                    // cout << "check" << end2[cur2][k] << endl;
                    if(ok[end2[cur2][k]] && lens[end2[cur2][k]] > j-fstx) ans++;
                }
                cur2 = fail2[cur2];
            }
            cur1 = cur1p;
            while(cur1 != 1)
            {
                for(int k = 0;k < end1[cur1].size();k++)
                {
                    // cout << "erase" << end1[cur1][k] << endl;
                    ok[end1[cur1][k]] = 0;
                }
                cur1 = fail1[cur1];
            }
            cur1 = cur1p; cur2 = cur2p;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
