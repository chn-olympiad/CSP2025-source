#include <bits/stdc++.h>

using namespace std;

struct p
{
    int a;
    int b;
    int c;
};
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int k;
    cin >> k;
    while(k--)
    {
        int n;
        cin >> n;
        p s[n];
        for(int i = 0;i < n;i++)
            cin >> s[i].a >> s[i].b >> s[i].c;

        int t = 0;
        int tt = 0;
        int aa = 0,bb = 0,cc = 0;
        for(int i = 0;i < n;i++)
        {
            if(s[i].a > s[i].b && s[i].a > s[i].c)
            {
                bool a = false,b = false,c = false;
                if(aa < n/2)
                    a = true;
                else if(s[i].b > s[i].c)
                    b = true;
                else
                    c = true;

                if(a)
                {
                    t+=s[i].a;
                    aa++;
                }
                else if(b)
                {
                    t+=s[i].b;
                    bb++;
                }
                else
                {
                    t+=s[i].c;
                    cc++;
                }
            }
            if(s[i].b > s[i].a && s[i].b > s[i].c)
            {
                bool a = false,b = false,c = false;
                if(bb < n/2)
                    b = true;
                else if(s[i].a > s[i].c)
                    a = true;
                else
                    c = true;

                if(b)
                {
                    t+=s[i].b;
                    bb++;
                }
                else if(a)
                {
                    t+=s[i].a;
                    aa++;
                }
                else
                {
                    t+=s[i].c;
                    cc++;
                }
            }
            if(s[i].c > s[i].a && s[i].c > s[i].b)
            {
                bool a = false,b = false,c = false;
                if(cc < n/2)
                    c = true;
                else if(s[i].a > s[i].b)
                    a = true;
                else
                    b = true;

                if(c)
                {
                    t+=s[i].c;
                    cc++;
                }
                else if(a)
                {
                    t+=s[i].a;
                    aa++;
                }
                else
                {
                    t+=s[i].b;
                    bb++;
                }
            }
        }
        aa = 0,bb = 0,cc = 0;
        for(int i = n-1;i >= 0;i--)
        {
            if(s[i].a > s[i].b && s[i].a > s[i].c)
            {
                bool a = false,b = false,c = false;
                if(aa < n/2)
                    a = true;
                else if(s[i].b > s[i].c)
                    b = true;
                else
                    c = true;

                if(a)
                {
                    tt+=s[i].a;
                    aa++;
                }
                else if(b)
                {
                    tt+=s[i].b;
                    bb++;
                }
                else
                {
                    tt+=s[i].c;
                    cc++;
                }
            }
            if(s[i].b > s[i].a && s[i].b > s[i].c)
            {
                bool a = false,b = false,c = false;
                if(bb < n/2)
                    b = true;
                else if(s[i].a > s[i].c)
                    a = true;
                else
                    c = true;

                if(b)
                {
                    tt+=s[i].b;
                    bb++;
                }
                else if(a)
                {
                    tt+=s[i].a;
                    aa++;
                }
                else
                {
                    tt+=s[i].c;
                    cc++;
                }
            }
            if(s[i].c > s[i].a && s[i].c > s[i].b)
            {
                bool a = false,b = false,c = false;
                if(cc < n/2)
                    c = true;
                else if(s[i].a > s[i].b)
                    a = true;
                else
                    b = true;

                if(c)
                {
                    tt+=s[i].c;
                    cc++;
                }
                else if(a)
                {
                    tt+=s[i].a;
                    aa++;
                }
                else
                {
                    tt+=s[i].b;
                    bb++;
                }
            }
        }
        cout << max(t,tt) << endl;
    }
    return 0;
}
