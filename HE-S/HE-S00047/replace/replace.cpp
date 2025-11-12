#include <bits/stdc++.h>
using namespace std;

map <string,string> mp;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q;
    scanf("%d %d",&n,&q);

    for(int i = 1;i <= n;i++)
    {
        string a,b;
        cin >> a >> b;
        mp[a] = b;
    }

    while(q--)
    {
        string a,b;
        cin >> a >> b;

        if(a.size() != b.size())
        {
            printf("0\n");
            continue;
        }

        int cnt = 0;
        int n = a.size();
        a = " " + a;
        b = " " + b;
        for(int l = 1;l <= n;l++)
        {
            bool flag = 1;
            for(int p = 1;p < l;p++)
            {
                if(a[p] != b[p])
                {
                    flag = 0;
                    break;
                }
            }

            if(flag == 0) continue;
            for(int r = l;r <= n;r++)
            {
                bool ff = 0;
                for(int o = r+1;o <= n;o++)
                {
                    if(a[o] != b[o])
                    {
                        ff = 1;
                        break;
                    }
                }
                if(ff == 1) continue;
                string x = "",y = "";
                for(int i = l;i <= r;i++)
                {
                    x += a[i];
                    y += b[i];
                }
                if(mp.count(x) == 0 || mp[x] != y) continue;
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
