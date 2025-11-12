#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

char buffer[65565];
unsigned li = 0;

char mgetchar()
{
    if (buffer[li] == '\0')
    {
        buffer[read(0, buffer, 65565)] = '\0';
        li = 0;
    }
    return buffer[li++];
}

template<typename T>
void in(T& i)
{
    i = 0;
    int f = 1;
    char c;
    do
    {
        c = mgetchar();
        if(c == '-') f = -1;
    }
    while(c < '0' || c > '9');
    while(c >= '0' && c <= '9') i = i * 10 + c - '0', c = mgetchar();
    i *= f;
}

template<>
void in(string& s)
{
    s = "";
    char c;
    while(isspace(c = mgetchar()));
    do
    {
        s += c;
    }
    while(!isspace(c = mgetchar()) && c != EOF);
}


void out(long long i)
{
    if(i < 0) putchar('-'), i = -i;
    if(i < 10) putchar(i + '0');
    else out(i / 10), putchar(i % 10 + '0');
}

void out(int i)
{
    if(i < 0) putchar('-'), i = -i;
    if(i < 10) putchar(i + '0');
    else out(i / 10), putchar(i % 10 + '0');
}


void out(string& s)
{
    for(int i = 0; i < s.size(); ++i)
    {
        putchar(s[i]);
    }
}


void out(string&& s)
{
    for(int i = 0; i < s.size(); ++i)
    {
        putchar(s[i]);
    }
}

struct state
{
    int index;
    int val;
    state(int a, int b):index(a), val(b) {}
};

struct cmp
{
    bool operator()(const state& a, const state& b) const {
        return a.val > b.val;
    }
};

void prim(long long& res, vector< vector<int> >& g, vector<int>& visited, vector<int>& p, int& n)
{
    state s(0, 0), tmp(0, 0);
    priority_queue<state, vector<state>, cmp> pq;
    pq.push(s);
    while(!pq.empty())
    {
        int cindex, cval;
        s = move(pq.top());
        pq.pop();
        cindex = s.index;
        cval = s.val;
        if(visited[cindex] == 1) 
        {
            
            continue;
        }
        else if(cindex >= n) res += p[cindex - n];
        res += cval;
        for(int i = 0; i < g[cindex].size(); ++i)
        {
            if(visited[i] == 0 && g[cindex][i] != -1) 
            {
                tmp.index = i;
                tmp.val = res + g[cindex][i];
                pq.push(tmp);
            }
        }
    }
}

int main()
{
    //////////////////////////////////////jian cha
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    //////////////////////////////////////
    int n, m, k, u, v, w;
    long long res = 0;
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    /*
    in(n);
    in(m);
    in(k);
    */
    cin >> n >> m >> k;
    vector< vector<int> > g(n + k, vector<int>(n + k, -1));
    vector<int> p (k, -1), visited(n + k);
    //build
    for(int i = 0; i < m; ++i)
    {
        /*
        in(u);
        in(v);
        in(w);
        */
        cin >> u >> v >> w;
        g[u][v] = w;
        g[v][u] = w;
    }
    for(int j = 0; j < k; ++j)
    {
        //in(w);
        cin >> w;
        p[j] = w;
        for(int i = 0; i < n; ++i)
        {
            //in(w);
            cin >> w;
            g[n + j][i] = w;
            g[i][n + j] = w;
        }
    }
    //
    prim(res, g, visited, p, n);
    //out(res);
    cout << res << '\n';
    //out("\n");
    return 0;
}
