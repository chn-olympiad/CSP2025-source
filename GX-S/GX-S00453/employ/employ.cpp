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

void traverse(int& res, vector<int>& c, vector<int>& s, vector<int>& visited, int& m, int index)
{
    if(index >= m) 
    {
        ++res;
    }
    //if(index = c.size() - 1) return;
    //base case

    for(int i = 0; i < c.size(); ++i)
    {
        res
        if(visited[i] == 0 && c[i] > s[index] && s[index] != -1)
        {
            ++visited[i];
            ++index;
            traverse(res, c, s, visited, m, index);
            --visited[i];
            --index;
        }
    }
}

void a()

int main()
{
    /////////////////////////////////////////ji de
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    /////////////////////////////////////////
    int n, m, tmp, t0, res;
    string str;
    in(n);
    in(m);
    vector<int> c(n), s(n, -1), visited(n, 0);
    in(str);
    for(int i = 0; i < c.size(); ++i)
    {
        in(tmp);
        c[i] = tmp;
    }
    tmp = 0;    //index
    t0 = 0;
    for(int i = 0; i < str.size(); ++i) //zip
    {
        if(str[i] == '0') 
        {
            ++t0;
        }
        else
        {
            s[tmp] = t0;
            ++tmp;
        }
    }
    if(tmp < m)  //imposeble ..what ever
    {
        out("\0");
        out("\0");
        return 0;
    }
    
    res = 0;
    traverse(res, c, s, visited, m, 0);
    out(res);
    out("\n");
    return 0;
}