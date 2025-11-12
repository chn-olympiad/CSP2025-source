#include <bits/stdc++.h>
using namespace std;

map<string,string> mp;

int box1[5000005];
int box2[5000005];

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    string sa,sb;
    cin >> sa >> sb;
    mp[sa] = sb;
    int cnta = 0,cntb = 0,cntc = 0;
    for(int i = 0;i < sa.size();i++)
    {
        if(sa[i] == 'a')cnta++;
        else if(sa[i] == 'b')cntb++;
        else cntc++;
    }
    bool flag = false;
    if(cntb == 1 && cntc == 0)flag = true;
    if(flag)
    {
        if(sa.find('b') > sb.find('b'))
        {
            box1[sa.find('b') - sb.find('b')]++;
        }
        else
        {
            box2[sb.find('b') - sa.find('b')]++;
        }
    }
    for(int i = 2;i <= n;i++)
    {
        string s1,s2;
        cin >> s1 >> s2;
        mp[s1] = s2;
        if(flag)
        {
            if(s1.find('b') > s2.find('b'))
            {
                box1[s1.find('b') - s2.find('b')]++;
            }
            else
            {
                box2[s2.find('b') - s1.find('b')]++;
            }
        }
    }
    while(q--)
    {
        string t1,t2;
        cin >> t1 >> t2;
        int n = t1.size();
        if(flag)
        {
            if(t1.find('b') > t2.find('b'))
            {
                cout << box1[t1.find('b') - t2.find('b')] << endl;
            }
            else cout<< box2[t2.find('b') - t1.find('b')] << endl;
            continue;
        }
        int cnt = 0;
        int l = -1,r = n;
        for(int i = 0;i < n;i++)
        {
            if(t1[i] != t2[i])
            {
                l = i;
                break;
            }
        }
        for(int i = n - 1;i >= 0;i--)
        {
            if(t1[i] != t2[i])
            {
                r = i;
                break;
            }
        }
        //cout << l << " " << r << endl;
        for(int i = 0;i <= l;i++)
        {
            for(int j = r;j < n;j++)
            {
                if(mp[t1.substr(i,j - i + 1)] == t2.substr(i,j - i + 1))
                {
                    cnt++;
                }
                //cout << t1.substr(i,j - i + 1) << " " << mp[t1.substr(i,j - i + 1)] << " " << t2.substr(i,j - i + 1) << endl;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
