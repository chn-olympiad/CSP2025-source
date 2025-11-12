#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5;
ll T, n, ans = 0;
bool vis[N];
struct node
{
    ll l, mid, r, pos;
}a[N];

inline bool cmpl(node x, node y)
{
    return x.l > y.l;
}
inline bool cmpmid(node x, node y)
{
    return x.mid > y.mid;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        ans = 0;

        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i].l >> a[i].mid >> a[i].r;
            a[i].pos = i;
        }

        ll suma = 0, sumb = 0;

        sort(a+1, a+1+n, cmpl);
        for(int i = 1; i <= n/2; ++i)
        {
            suma += a[i].l;
            vis[a[i].pos] = 1;
        }
        sort(a+1, a+1+n, cmpmid);
        for(int i = 1; i <= n; ++i)
        {
            if(vis[i] == 1) continue;
            else if(vis[i] == 0)
            {
                suma += a[i].mid;
                vis[a[i].pos] = 1;
            }
        }

        memset(vis, 0, sizeof(vis));
        sort(a+1, a+1+n, cmpmid);
        for(int i = 1; i <= n/2; ++i)
        {
            sumb += a[i].mid;
            vis[a[i].pos] = 1;
        }
        sort(a+1, a+1+n, cmpl);
        for(int i = 1; i <= n; ++i)
        {
            if(vis[i] == 1) continue;
            else if(vis[i] == 0)
            {
                sumb += a[i].l;
                vis[a[i].pos] = 1;
            }
        }
        ans = max(suma, sumb);
        cout << ans << "\n";
    }
    return 0;
}

/*
/*#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//typedef unsigned long long ull;
//const int N = 4e5;
//const int I = 1e5 + 7;
//const int M = 2e4 + 7;
//int T, n;
//ll  a[N][5], asn, lim[N][5], tot, biao[5000008];
//inline void dfs(int ceil, ll cnt, ll maxx)
//{
 //   ll sum = 0;
   // if(ceil == n)
    //{
//        for(int i = 1; i <= 3; ++i)
  //      {
    //        if(lim[ceil - 1][i] < maxx)
      //      {
        //        cnt += a[ceil][i];
          //      tot++;
            //    biao[tot] = cnt;
              //  cnt -= a[ceil][i];
      ///      }
        //}
    //}
   // else
   // {
     //   for(int i = 1; i <= 3; ++i)
       //     lim[ceil][i] = lim[ceil - 1][i];
      //  for(int i = 1; i <= 3; ++i)
        //{
        //    if(lim[ceil][i] < maxx)
        //    {
          //      cnt += a[ceil][i];
           //     lim[ceil][i]++;
             //   if(lim[ceil][1] < maxx)
               // {
                //    dfs(ceil+1, cnt, maxx);
               // }
               // if(lim[ceil][2] < maxx)
                //{
                 //   dfs(ceil+1, cnt, maxx);
                //}
                //if(lim[ceil][3] < maxx)
                //{
                  //  dfs(ceil+1, cnt, maxx);
               // }
                //cnt -= a[ceil][i];
          //  }
        //}
    //}
//}
//int main()
//{
 //   freopen("club.in", "r", stdin);
  //  freopen("club.out", "w", stdout);
   // ios::sync_with_stdio(0);
    //cin.tie(0);
   // cin >> T;
//    while(T--)
  //  {
    //    cin >> n;
      //  ll maxx = n / 2;
       // asn = tot = 0;
      //  memset(a, 0, sizeof(a));
       // memset(biao, 0, sizeof(biao));
        //memset(lim, 0, sizeof(lim));
        ///for(int i = 1; i <= n; ++i)
           // for(int j = 1; j <= 3; ++j)
             //   cin >> a[i][j];
       // for(int i = 1; i <= 3; ++i)
        //{
          //  lim[1][i]++;
            //dfs(2, lim[1][i], maxx);
            //lim[1][i]--;
      //  }
        //for(ll i = 1; i <= tot; ++i)
//            asn = max(asn, biao[i]);
  //      cout << asn << "\n";
    //}
    //return 0;
//}*/
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5;
const int I = 1e5 + 7;
const int M = 2e4 + 7;
ll T, n, x[N][5], asn, lim[N][5], tot;
bool usedi[N];
inline bool cmp(ll x, ll y)
{
    return x > y;
}
int main()
{
    freopen("club.in", "r", stdin); /////////////
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        asn = 0;
        ll maxn = n / 2;
        memset(x, 0, sizeof(x));
        priority_queue<pair<ll, ll> > aa;
        priority_queue<pair<ll, ll> > ab;
        priority_queue<pair<ll ,ll> > ac;
        priority_queue<pair<ll, ll> > ba;
        priority_queue<pair<ll, ll> > bb;
        priority_queue<pair<ll ,ll> > bc;
        priority_queue<pair<ll, ll> > ca;
        priority_queue<pair<ll, ll> > cb;
        priority_queue<pair<ll ,ll> > cc;
        for(ll i = 1; i <= n; ++i)
        {
            //ll ai[5];
            for(ll j = 1; j <= 3; ++j)
            {
                cin >> x[i][j];
                //pos[i][ x[i][j] ] = j;
                //ai[j] = x[i][j];
                if(j == 1)
                {
                    aa.push({x[i][j], i});
                    ba.push({x[i][j], i});
                    ca.push({x[i][j], i});
                }
                if(j == 2)
                {
                    ab.push({x[i][j], i});
                    bb.push({x[i][j], i});
                    cb.push({x[i][j], i});
                }
                if(j == 3)
                {
                    ac.push({x[i][j], i});
                    bc.push({x[i][j], i});
                    cc.push({x[i][j], i});
                }
            }
            //sort(ai+1, ai+1+3, cmp);
            //for(ll j = 1; j <= 3; ++j)
                //cout << ai[j] << " ";
            //cout <<endl;
        }
        /*cout <<"a\n";
        while(!a.empty())
        {
            ll t = a.top().first;
            cout << t;
            a.pop();
        }*/
        //cout << maxn <<endl;

        /*ll ansa = 0;
        /// do a;
        memset(usedi, 0, sizeof(usedi));
        tot = 0;
        while(tot <= maxn)
        {
            ll t = aa.top().first;
            ansa += t;
            usedi[aa.top().second] = 1;
            aa.pop();
            tot++;
        }
        while(tot <= n)
        {
            //while( ( usedi[ ab.top().second] ) == 1 ){ ab.pop();}
            //while(usedi[ac.top().second] == 1){ ac.pop();}
            ll bval = ab.top().first, cval = ac.top().first, bpos = ab.top().second, cpos = ac.top().second;
            if(bval >= cval)
            {
                if(usedi[ ab.top().second ]  == 0)
                {
                    ansa += bval;
                    usedi[bpos] = 1;
                    tot++;
                }
                ab.pop();
            }
            else if(bval < cval)
            {
                if(usedi[ ac.top().second] == 0)
                {
                    ansa += cval;
                    usedi[cpos] = 1;
                    tot++;
                }
                ac.pop();
            }
        }
        asn = max(asn, ansa);

        ////do b
        /*ll ansb = 0;
        memset(usedi, 0, sizeof(usedi));
        tot = 0;
        while(tot <= maxn)
        {
            ll t = bb.top().first;
            ansb += t;
            usedi[bb.top().second] = 1;
            bb.pop();
            tot++;
        }
        while(tot <= n)
        {
            while(usedi[ba.top().second] == 1){ ba.pop();}
            while(usedi[bc.top().second] == 1){ bc.pop();}
            ll aval = ba.top().first, cval = bc.top().first, apos = ba.top().second, cpos = bc.top().second;
            if(aval >= cval)
            {
                ansb += aval;
                usedi[apos] = 1;
                tot++;
            }
            else if(aval < cval)
            {
                ansb += cval;
                usedi[cpos] = 1;
                tot++;
            }
        }
        asn = max(asn, ansb);

        ////do c
        ll ansc = 0;
        memset(usedi, 0, sizeof(usedi));
        tot = 0;
        while(tot <= maxn)
        {
            ll t = cc.top().first;
            ansc += t;
            usedi[cc.top().second] = 1;
            cc.pop();
            tot++;
        }
        while(tot <= n)
        {
            while(usedi[ca.top().second] == 1){ ca.pop();}
            while(usedi[cb.top().second] == 1){ cb.pop();}
            ll aval = ca.top().first, bval = cb.top().first, apos = ca.top().second, bpos = cb.top().second;
            if(aval >= bval)
            {
                ansc += aval;
                usedi[apos] = 1;
                tot++;
            }
            else if(aval < bval)
            {
                ansc += bval;
                usedi[bpos] = 1;
                tot++;
            }
        }*/
        /*cout << asn << endl;
    }
    return 0;
}*/
