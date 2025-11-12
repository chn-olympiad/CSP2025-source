#include <bits/stdc++.h>
using namespace std;

string isqueue(string s)
{
    int cnt=1;
    for(int i=1; i<=s.length(); i++)
    {
        if (s[cnt] >= s[i])
        {
            s[cnt]=s[i-1];
            cnt++;
        }
    }
    return s;
}
long long findnumber(string p,long long y)
{
    int cnt =0;
    int i=1;
    while (p[i]==y)
    {
        i++;
        cnt++;
        return cnt;
    }
}
long long seatplace(long long f,int w,int g)
{
    for (int i=1; i<=w; i++)
    {
        for (int j=1; j<= g; j++)
        {
            if (f==i*j)
            {
                return j;
            }
        }
    }
}
long long seatnum(long long f,int w,int g)
{
    for (int i=1; i<=w; i++)
    {
        for (int j=1; j<= g; j++)
        {
            if (f==i*j)
            {
                return i;
            }
        }
    }
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,m;
    cin >> n >> m;
    string a;
    int x;
    for (int i=1; i<=n*m; i++)
    {
        cin >> a[i];
        x=a[1];
    }
    cout << seatplace(findnumber(isqueue(a),x),n,m) <<" "<< seatnum(findnumber(isqueue(a),x),n,m) << endl;
    return 0;
}
