#include <bits/stdc++.h>

using namespace std;

int n,q;
map <string,string> s;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i<=n;++i)
    {
        string s1,s2;
        cin >> s1 >> s2;
        s[s1] = s2;
    }

    for(int i = 1;i<=q;++i)
    {
        string t1,t2,tt1 = "",tt2 = "";
        cin >> t1 >> t2;
        int l,r;
        for(int j = 0;j <= t1.size() - 1;++j)
            if(t1[j] != t2[j])
            {
                l = j;
                break;
            }

        for(int j = t1.size() - 1;j >= 0;--j)
            if(t1[j] != t2[j])
            {
                r = j;
                break;
            }

        for(int j = l;j <= r;++j)
        {
            tt1 += t1[j];
            tt2 += t2[j];
        }

        int ans = 0;
        if(s[tt1] == tt2)
            ans ++;

        for(int j = l-1;j >= 0;--j)
        {
            string tl = "",tr = "";
            for(int p = j;p <= l-1;++p)
                tl += t1[p];
            for(int k = r+1;k <= t1.size() - 1;++k)
            {
                tr += t1[k];
                if(s[tl+tt1+tr] == tl+tt2+tr)
                     ans ++;
            }
        }
        cout << ans << endl;
    }

	return 0;
}
