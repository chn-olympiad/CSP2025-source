#include<bits/stdc++.h>
using namespace std;
const int Max = 1e5 + 5,Mod = 998244353;

struct WOW
{
    int n,m;
    string ss;
    vector<int>pa;
    long long ant = 0;
    vector<long long>jie;
    void DFS(int now,int val,int die,int in)
    {
    	if(val == m)
        {
            int lst = n - in + 1;
            cout <<now <<" " <<val <<" "  <<die <<" " <<in <<endl; 
            cout <<lst <<endl;
            ant += jie[lst];
            ant %= Mod;
        }
        if(in == n + 1)
            return;
            
        int dd = die,vv = val;
        for(int q=1;q <=n;q++)
        {
            int it = (1 <<(q -1));
            if((now & it) == 0)
            {
                if(pa[q] <= die || (ss[in] - '0') == 0)
                    dd ++ ;
                else
                    vv ++;
            }
            
            DFS(now + it,vv,dd,in + 1);
        }
    }
    void baoli()
    {
        cin >>n >>m;
        pa.resize(n + 1);
        jie.resize(n +1);
        jie[1] = 1;
        for(int q=2;q <=n;q++)
        {
            jie[q] = jie[q-1] * q;
            jie[q] %=Mod;
        }
        cin >>ss;
        ss = " " + ss;
        for(int q=1;q <=n;q++)
			cin >>pa[q];
        DFS(0,0,0,1);
        cout <<ant <<endl;
    }
    long long dp[Max][Max];
    bool vis[Max] = {false};
    void DFS(int now,int die,int pass,int pos)
    {
        if(vis[now])return ;
        vis[now] = true;
        if(pos == n + 1)
        {
            if(pass >=m)
                ant ++;
        }
        for(int q=1;q <=n;q++)
        {
            if(vis[q])continue;
            if(s[pos] - '0' == 0 || die >= pa[q])
                die++;
            else
                pass ++;
            DFS(q,die,pass,pos+ 1);
        }
    }
    void Solve()
    {
        cin >>n >>m;
        cin >>ss;
        ss = " " + ss;

        pa.resize(n + 1);
        for(int q=1;q <=n;q++)
            cin >>pa[q];
        DFS(0,0,0,1);
        cout <<ant <<endl;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);


        WOW OWO;
        OWO.baoli();


    return 0;
}
