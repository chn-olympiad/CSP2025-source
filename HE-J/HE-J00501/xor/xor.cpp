#include <bits/stdc++.h>
using namespace std;
string aba[500005];
bool ab[500005];
long long n,asdfg,sum = 0;
string k;
string aws(int q)
{
    if (q == 0)
        return "";
    string w;
    if (q % 2 == 0)
        w = '0';
    else
        w = '1';
    q /= 2;
    return (aws(q))+w;
}
string anwei(string a,string b)
{
    string w = "";
    if (a.size() <= b.size())
    {
        for (int i = 0;i < b.size()-a.size();i++)
            w += b[i];
        for (int i = 0;i < a.size();i++)
            if (a[i] == b[i+b.size()-a.size()])
                w += '0';
            else
                w += '1';
    }
    else
    {
        for (int i = 0;i < a.size()-b.size();i++)
            w += a[i];
        for (int i = 0;i < b.size();i++)
            if (b[i] == a[i+a.size()-b.size()])
                w += '0';
            else
                w += '1';
    }
    return w;
}
bool duibi(string a,string b)
{
    int er = a.size()-b.size();
    if (er <0)
    {
        return 1;
    }
    return 0;
}
int zuizhi(int l,int r)
{
    if (l >= r)
    {
        return 0;
    }
    string dangqian = aba[l];
    for (int i = l;i <= r;i++)
    {
        if(anwei(aba[i],dangqian) == k)
        {
            return 1+zuizhi(i+1,r);
        }
    }
    return 0;
}
int main()
{
    freopen("xor1.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> asdfg;
    k = aws(asdfg);
    for (int i = 1;i <= n;i++)
    {
        long qer;
        cin >> qer;
        aba[i] = aws(qer);
        if (duibi(k,aba[i]))
        {
            ab[i] = 0;
        }
        else if (qer == asdfg)
        {
            ab[i] = 0;
            sum++;
        }
        else
            ab[i] = 1;
    }
    int l = 1,r=n;

    for (int i = 1;i <= n;i++)
    {
        if (ab[i] == 0)
        {
            r = i-1;
            sum += zuizhi(l,r);
            l = i+1;
        }
    }
    if (ab[n] == 1)
    {
        r = n;
        sum += zuizhi(l,r);
    }
    cout << sum;
    return 0;
}
